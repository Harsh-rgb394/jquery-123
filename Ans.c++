#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int work(int arr[], int n)
{
    if (n == 0)
    {
        return arr[0] * 1;
    }

    int take = arr[n] * n + 1 + work(arr, n - 1);

    int notake = 0 + work(arr, n - 1);

    return max(take, notake);
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
    // vector<int> ans;
    sort(arr, arr + n);
    cout << work(arr, n - 1);

    return 0;
}