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
    // int a, b, c;
    vi divisors;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal, print only one
            if (n / i == i)
            {
                divisors.PB(i);
            }

            else
            {
                divisors.PB(i);
                divisors.PB(n / i);
            } // Otherwise print both
            // printf("%d %d ", i, n / i);
        }
    }

    sort(divisors.begin(), divisors.end());
    int a = divisors[1];
    // trace(a);
    n /= a;
    vi div2;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // If div2 are equal, print only one
            if (n / i == i)
            {
                div2.PB(i);
            }

            else
            {
                div2.PB(i);
                div2.PB(n / i);
            } // Otherwise print both
            // printf("%d %d ", i, n / i);
        }
    }

    int b;
    sort(div2.begin(), div2.end());
    // cout << "Divisors of n " << n << "\n";
    // for (auto x : div2)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";
    for (auto x : div2)
    {
        if (x != 1 && x != a)
        {
            b = x;
            break;
        }
    }

    int c = n / b;
    if (a != c && b != c && a != b && c != 0 && c != 1)
    {
        cout << "YES\n";
        cout << a << " " << b << " " << c << "\n";
    }
    else
    {
        cout << "NO\n";
    }
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