#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;

#define PB push_back
#define F first
#define S second
#define MP make_pair

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
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

ll powmod(ll x, ll y, ll mod) {
    ll res = 1;
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

const ll MOD = 1e9 + 7;
int case_no = 1;

void solve() {
    int ans = 0;
    ll n, d, c, m;
    cin >> n >> d >> c >> m;
    string s;
    cin >> s;

    int dc = 0, feeded = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') {
            dc++;
        }
    }

    bool f = true;
    bool dog = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') {
            dog = true;
            if (d > 0) {
                d--;
                feeded++;
                c += m;
            } else {
                f = false;
                break;
            }
        } else if (s[i] == 'C') {
            if (c > 0) {
                c--;
            } else {
                f = false;
                break;
            }
        }
    }

    // trace(f, dc, feeded);

    string val = "NO";

    if (dc == feeded) {
        f = true;
    }

    if (f) {
        val = "YES";
    }

    cout << "Case #" << case_no << ": " << val << "\n";
    case_no++;
}

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}
