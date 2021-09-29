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
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
	const char *comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}
#else
#define trace(...)
#endif

ll powmod(ll x, ll y, ll mod)
{
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

void solve()
{
	ll n;
	cin >> n;
	vector<ll> arr;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		arr.PB(x);
	}

	ll cost = 0;

	ll mn = *min_element(arr.begin(), arr.end());
	ll mx = *max_element(arr.begin(), arr.end());

	bool minAdded = false;
	bool maxAdded = false;

	deque<ll> dq;
	for (ll i = 0; i < n; i++) {
		if (arr[i] == mn) {
			dq.push_front(mn);
			minAdded = true;
		} else if (arr[i] == mx) {
			dq.push_back(mx);
			maxAdded = true;
		} else {


			if (minAdded && !maxAdded) {
				dq.push_back(arr[i]);
			} else if (maxAdded && !minAdded) {
				dq.push_front(arr[i]);
			} else if (maxAdded && minAdded) {

				// chose best position to add

			} else {

				// chose best position to add


			}


		}
	}








}

int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
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
