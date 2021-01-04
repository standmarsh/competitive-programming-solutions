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

int isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++)
    {
        int j;

        /* For current index i, check for
 pattern match */
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return i;
    }

    return -1;
}

void solve()
{
    vector<string> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.PB(s);
    }
    sort(v.begin(), v.end(), [](const std::string &first, const std::string &second) {
        return first.size() < second.size();
    });
    // for (auto x : v)
    // {
    //     cout << x << "\n";
    // }
    reverse(v.begin(), v.end());
    // for (auto x : v)
    // {
    //     cout << x << "\n";
    // }
    for (int i = 0; i < n - 1; i++)
    {
        string s1 = v[i];
        string s2 = v[i + 1];
        // trace(s1, s2);
        // s2 should contain s1
        if (isSubstring(s2, s1) == -1)
        {
            cout << "NO\n";
            return;
        }
        // if (s1 == s2)
        // {
        //     //nothing
        // }
        // else if (s2.find(s1) != string::npos)
        // {
        //     cout << "NO\n";
        //     return;
        // }
    }
    cout << "YES\n";
    reverse(v.begin(), v.end());
    for (auto x : v)
    {
        cout << x << "\n";
    }
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