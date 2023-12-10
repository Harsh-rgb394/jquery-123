#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int getmax(int start, int end, int num, int arr[])
{
    int count = 0;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] > num)
        {
            count++;
        }
    }
    return count;
}
vector<int> work(int arr[], int n)
{
    vector<int> ans(n);
    ans[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int x = arr[i];
        int count = 0;
        for (int j = i; j > 0; j--)
        {

            if (arr[j - 1] > x)
            {
                count++;
            }
        }
        ans.push_back(count);
    }
    // reverse(arr, arr + n);

    return ans;
}

vector<int> work2(int arr[], int n)
{
    vector<int> ans;

    set<int> st;
    int x;
    for (int i = 0; i < n; i++)
    {
        if (st.find(arr[i]) != st.end())
        {
            x = arr[i];
            ans.push_back(arr[i]);
        }
        else
        {
            st.insert(arr[i]);
        }
    }

    // int sum = 0;
    for (auto it = st.begin(); it != st.end(); it++)
    {
        if ((*it) + (*it + 1) % 2 == 0)
        {
            int a = (*it) + (*it + 1) / 2;
            ans.push_back(a);
        }
    }

    // int sum1 = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     sum1 += arr[i];
    // }
    // int p;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i + 1] - arr[i] > 1)
    //     {
    //         p = arr[i + 1] - 1;
    //     }
    // }
    // ans.push_back(p);
    return ans;
}

int main()
{

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = work2(arr, n);
    int m = ans.size();
    for (int j = 0; j < m; j++)
    {
        cout << ans[j] << " ";
    }

    return 0;
}