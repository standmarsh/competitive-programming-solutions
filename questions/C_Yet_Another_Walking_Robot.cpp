#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

#define PB push_back
#define F first
#define S second
#define MP make_pair

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

int powmod(int x, int y, int mod)
{
    int res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<pair<int, int>, int> vis;
    pair<int, int> pos;
    pos.F = 0;
    pos.S = 0;
    vis[pos] = 0;

    // (x,y)
    int minnDistance = 1e9;
    vi ans;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> curr = pos;
        if (s[i] == 'U')
        {
            curr.S += 1;
        }
        else if (s[i] == 'D')
        {
            curr.S -= 1;
        }
        else if (s[i] == 'R')
        {
            curr.F += 1;
        }
        else if (s[i] == 'L')
        {
            curr.F -= 1;
        }

        if (vis.find(curr) != vis.end())
        {

            int dist = i + 1 - (vis[curr]);
            if (dist < minnDistance)
            {
                minnDistance = dist;
                ans.clear();
                ans.PB(vis[curr] + 1);
                ans.PB(i + 1);
            }
            vis[curr] = i + 1;
        }
        else
        {
            vis[curr] = i + 1;
        }

        pos = curr;
    }

    if (ans.size() != 2)
    {
        cout << -1 << "\n";
        return;
    }

    cout << ans[0] << " " << ans[1] << "\n";
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
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