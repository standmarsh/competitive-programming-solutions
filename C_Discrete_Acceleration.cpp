#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

#define pb push_back
#define F first
#define S second
#define mp make_pair

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
    int n, l;
    cin >> n >> l;
    cout << fixed;
    cout.precision(10);
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    /*
    speed = distance / time
    time = distance/speed
    */

    int initialA = 1, initialB = 1;
    double dA = 0, dB = l;
    int ptrA = 0, ptrB = n - 1;
    double ans = 0;
    int sa = 1, sb = 1;

    while (ptrA <= ptrB)
    {
        double da = a[ptrA] - dA;
        double db = dB - a[ptrB];
        double ta = (1.0) * (da) / sa;
        double tb = (1.0) * (db) / sb;
        if (ta <= tb)
        {
            ans += ta;
            sa++;
            dA += da;
            dB -= (1.0) * (sb) * (ta);
            ptrA++;
        }
        else
        {
            ptrB--;
            ans += tb;
            sb++;
            dB -= db;
            dA += (1.0) * (tb) * (sa);
        }
        // trace(ptrA);
        // trace(ptrB);
    }
    double remDist = dB - dA;
    // trace(remDist);
    cout << ans + (1.0) * remDist / (sa + sb) << "\n";
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