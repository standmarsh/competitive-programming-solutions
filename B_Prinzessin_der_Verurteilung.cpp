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

int n;
string s;
vector<string> all;

void print()
{
    string chk = "a";

    int cnt = 0;
    while (cnt < 300)
    {
        all.PB(chk);
        int len = chk.length();
        if (chk[0] == 'z')
        {
            chk = "";
            for (int i = 0; i <= len; i++)
            {
                chk += "a";
            }
        }
        else
        {
            // find first non z character
            int br;
            for (int i = len - 1; i >= 0; i--)
            {
                // trace(i);
                if (chk[i] != 'z')
                {
                    // trace(chk[i], i);
                    chk[i] = chk[i] + 1;
                    br = i;
                    break;
                }
            }
            // trace(br);
            for (int i = br + 1; i < len; i++)
            {
                chk[i] = 'a';
            }
        }
        cnt++;
        trace(chk);
    }
}

void solve()
{

    cin >> n;
    cin >> s;
    string chk = "a";
    vector<string> v;

    for (int i = 0; i < n; i++)
    {
        for (int len = 1; len <= n - i; len++)
        {
            string str = s.substr(i, len);
            v.PB(str);
        }
    }

    sort(v.begin(), v.end());
    // for (auto x : v)
    // {
    //     cout << x << "\n";
    // // }

    while (true)
    {
        if (!binary_search(v.begin(), v.end(), chk))
        {
            // found
            // trace(chk);
            cout << chk << "\n";
            return;
        }
        else
        {
            // reverse(chk.begin(), chk.end());
            int len = chk.length();
            if (chk[0] == 'z')
            {
                chk = "";
                for (int i = 0; i <= len; i++)
                {
                    chk += 'a';
                }
            }
            else
            {
                // find first non z character
                int br;
                for (int i = len - 1; i >= 0; i--)
                {
                    // trace(i);
                    if (chk[i] != 'z')
                    {
                        // trace(chk[i], i);
                        chk[i] = chk[i] + 1;
                        br = i;
                        break;
                    }
                }
                // trace(br);
                for (int i = br + 1; i < len; i++)
                {
                    chk[i] = 'a';
                }
                // for (int i = br + 1; i >= 0; i--)
                // {
                //     chk[i] = 'a';
                // }
            }
        }
        // trace(chk);
    }
}

bool cmp(string s1, string s2)
{
    if (s1.length() > s2.length())
    {
        return true;
    }
    else if (s1.length() == s2.length())
    {
        return s1 > s2;
    }
    else
    {
        return false;
    }
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // print();

    // sort(all.begin(), all.end(), cmp);

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}