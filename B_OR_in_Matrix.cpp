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

int a[105][105];
int n, m;

bool oneAround(int i, int j)
{
    if (a[i + 1][j] == 1 || a[i - 1][j] == 1 || a[i][j + 1] == 1 || a[i][j - 1] == 1)
        return true;

    return false;
}

bool zeroAround(int i, int j)
{
    if (a[i + 1][j] == 0 || a[i - 1][j] == 0 || a[i][j + 1] == 0 || a[i][j - 1] == 0)
        return true;
    return false;
}

void solve()
{
    int n, m;
    cin >> m >> n;
    bool B[m][n], A[m][n], C[m][n];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> B[i][j];
            A[i][j] = 1;
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (B[i][j] == 0)
            {
                for (int k = 0; k < n; ++k)
                {
                    A[i][k] = 0;
                }
                for (int k = 0; k < m; ++k)
                {
                    A[k][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (A[i][j])
            {
                for (int k = 0; k < n; ++k)
                {
                    C[i][k] = 1;
                }
                for (int k = 0; k < m; ++k)
                {
                    C[k][j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (C[i][j] != B[i][j])
            {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
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