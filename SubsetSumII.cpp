#include <bits/stdc++.h>
using namespace std;

void Subsets(int ind, vector<int> &arr, vector<int> &ds, vector<vector<int>> &final)
{
    final.push_back(ds);
    for (int i = ind; i < arr.size(); i++)
    {
        if (i != ind && arr[i] == arr[i - 1])
            continue;
        ds.push_back(arr[i]);
        Subsets(i + 1, arr, ds, final);
        ds.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<int> ds;
    vector<vector<int>> final;
    Subsets(0, arr, ds, final);
    // sort(final.begin(), final.end());
    return final;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, input;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            v.push_back(input);
        }
        vector<vector<int>> finale;
        finale = uniqueSubsets(n, v);
        sort(finale.begin(), finale.end());
        for (int i = 0; i < finale.size(); i++)
        {
            for (int j = 0; j < finale[i].size(); j++)
            {
                cout << finale[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}