#include <iostream>
#include <vector>
using namespace std;

int work(int n, vector<int> &dp)
{

    if (n < 1000)
    {
        return 0;
    }

    if (n == 1000)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = 1 + work(n - 1, dp);
}

int main()
{

    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    // n = n + 1;
    cout << work(n, dp);

    return 0;
}