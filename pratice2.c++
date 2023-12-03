#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int work2(vector<int> ans)
{
    int dec_value = 0;

    int base = 1;

    int len = ans.size();

    for (int i = len - 1; i >= 0; i--)
    {
        if (ans[i] == 1)

            dec_value += base;

        base = base * 2;
    }

    return dec_value;
}
int work(int n)
{
    vector<int> ans;

    while (n != 0)
    {
        int c = n % 2 == 0 ? 1 : 0;

        ans.push_back(c);
        n = n / 2;
    }

    int i = 0;
    int size = ans.size();
    int c = INT_MAX;

    while (i <= size - 1)
    {

        if (ans[i] == 1)
        {
            ans[i] = 0;
        }
        ans[i] = 1;

        c = min(c, work2(ans));
        // if (ans[i] == 1)
        // {
        //     ans[i] = 0;
        // }
        // ans[i] = 1;
        i++;
    }
    return c;
}

int main()
{
    int n;
    cin >> n;

    // vector<int> ans = {1, 1, 1, 1};

    cout << work(n);
    // vector<int> arr = work(n);

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i];
    // }

    return 0;
}