#include <bits/stdc++.h>
#include <deque>
#include <queue>
#include <utility>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;

ll powmod(ll x, ll y, ll mod) {
    ll res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

const ll MOD = 1e9 + 7;

void solve() {
    int q;
    cin >> q;

    set<ll> st;
    set<ll> snd; // does not contain entries inside st

    while (q) {

        ll choice, x;
        cin >> choice >> x;

        if (choice == (ll)1) {
            st.insert(x);
            snd.insert(x + 1);
            if (snd.find(x) != snd.end()) {
                snd.erase(x);
            }
        } else if (choice == (ll)2) {
            auto it = snd.lower_bound(x + 1);
            if (it == snd.end()) {
                cout << x + 1 << "\n";
            } else {
                cout << *it << "\n";
            }
        }

        q--;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t > 0) {
        solve();
        t--;
    }
}
