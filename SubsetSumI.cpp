#include <bits/stdc++.h>
using namespace std;

void subs(int i, int n, int sum, vector<int> &array, vector<int> &v, vector<int> &final)
{
    if (i == n)
    {
        final.push_back(sum);
        return;
    }

    subs(i + 1, n, sum, array, v, final);

    v.push_back(array[i]);
    sum += array[i];
    subs(i + 1, n, sum, array, v, final);
    sum -= array[i];
    v.pop_back();
}

vector<int> subsetSum(vector<int> &num)
{
    int sum = 0;
    vector<int> v, final;
    subs(0, num.size(), sum, num, v, final);
    return final;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int input;
        vector<int> a, v;
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            v.push_back(input);
        }
        a = subsetSum(v);
        sort(a.begin(), a.end());
        for (auto it : a)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}