#include <bits/stdc++.h>
using namespace std;

void com(int n, int i, int t, vector<int> &arr, vector<vector<int>> &ans, vector<int> &v)
{
    if (i == n)
    {
        if (t == 0)
        {
            // for (auto it : v)
            // {
            //     cout << it;
            // }

            // cout << endl;
            ans.push_back(v);
        }
        return;
    }

    if (arr[i] <= t)
    {
        v.push_back(arr[i]);
        com(n, i, t - arr[i], arr, ans, v);
        v.pop_back();
    }

    com(n, i + 1, t, arr, ans, v);

    // return ans;
}

vector<vector<int>> result(vector<int> &arr, int t)
{
    vector<vector<int>> ans;
    vector<int> v;
    com(arr.size(), 0, t, arr, ans, v);
    return ans; 
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    vector < vector<int>> res= result(arr,7);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}