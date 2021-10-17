#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

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
    //use cerr if u want to display at the bottom
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
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

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int left[n], right[n];
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        left[i] = -1;
        right[i] = n;
    }

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            left[i] = s.top();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        s.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }

        if (!s.empty())
        {
            right[i] = s.top();
        }
        s.push(i);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << left[i] << " ";
    // }
    // cout << "\n";

    // for (int i = 0; i < n; i++)
    // {
    //     cout << right[i] << " ";
    // }
    // cout << "\n";

    int ans[n + 1];
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; i++)
    {
        int len = right[i] - left[i] - 1;
        // trace(len);
        ans[len] = max(ans[len], a[i]);
    }
    for (int i = n - 1; i >= 1; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}