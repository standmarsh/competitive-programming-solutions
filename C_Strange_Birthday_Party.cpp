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
    ll n, m;
    cin >> n >> m;
    // ll a[n + 1];
    // ll b[m + 1];
    vector<ll> a(n + 1);
    vector<pair<int, int>> b(m + 1);
    a[0] = 0;
    b[0].F = 0;
    b[0].S = 0;

    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (ll i = 1; i <= m; i++)
    {
        ll x;
        cin >> x;
        b[i].F = x;
        b[i].S = 0;
    }

    sort(a.begin(), a.end());
    // reverse(a.begin(), a.end());
    // for (ll i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << "\n";

    // for (ll i = 0; i < b.size(); i++)
    // {
    //     cout << b[i].F << " " << b[i].S << "\n";
    // }

    ll ans = 0;
    ll ptr = 1;

    for (ll i = n; i >= 1; i--)
    {
        ll cost1 = b[a[i]].F;

        ll cost2 = b[ptr].F;
        if (ptr > m || b[ptr].S == 1)
        {
            cost2 = 1e9;
        }

        // trace(a[i], cost1, cost2);

        if (cost1 <= cost2)
        {
            //we are giving dollars directly
            ans += cost1;
        }
        else
        {
            ans += cost2;
            b[ptr].S = 1;
            ptr++;
        }
        // trace(ans, ptr);
    }
    // cout << "ANS\n";
    cout << ans << "\n";
}

int main()
{
    // freopen("filename_input.txt","r",stdin);
    // freopen("filename_output.txt","w",stdout);
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