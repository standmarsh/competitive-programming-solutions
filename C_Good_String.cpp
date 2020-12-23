#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int solve(const string &s, int x, int y)
{
    int res = 0;
    for (auto c : s)
        if (c - '0' == x)
        {
            ++res;
            swap(x, y);
        }

    if (x != y && res % 2 == 1)
        --res;

    return res;
}

void solve()
{
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            ans = max(ans, solve(s, i, j));

    cout << s.size() - ans << "\n";
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}