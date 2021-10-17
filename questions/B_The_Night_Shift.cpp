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
    ll q;
    cin >> q;
    vi v;
    ll sum = 0;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        v.PB(x);
        sum += x;
    }
    ll mod = sum % 5;
    // trace(mod);
    // cout << mod << "\n";
    ll num = 1;
    q++;
    ll ans = 0;
    for (ll i = 1; i <= 5; i++)
    {
        if ((sum + i) % q != 1)
        {
            ans++;
        }
    }
    cout << ans << "\n";

    // while (true)
    // {
    //     if ((sum + num) % (q) != 1)
    //     {
    //         cout << num << "\n";
    //         break;
    //     }
    //     num++;
    // }
}

int main()
{
    // freopen("filename_input.txt","r",stdin);
    // freopen("filename_output.txt","w",stdout);
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