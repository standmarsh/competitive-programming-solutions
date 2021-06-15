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

void primeCnt(map<ll,ll> &mp, ll a){
    for(ll i=2; i*i<=a; i++){
        if(a%i==0){
            ll cnt = 0;
            while(a%i==0){
                cnt++;
                a/=i;
            }
            mp[i] = cnt;
        }
    }
    if(a>1){
        mp[a] = 1;
    }
}


ll primeCnt2(ll a){
    ll cnt = 0;
    for(ll i=2; i*i<=a; i++){
        if(a%i==0){
            while(a%i==0){
                cnt++;
                a/=i;
            }
          
        }
    }
    if(a>1){
        cnt++;
    }
    // trace(cnt);
    return cnt;
}

vector<ll> primes;

ll cntPrimes(ll a){
    ll cnt = 0;
    ll ptr = 0;
    while(a>0 && ptr < primes.size()){
        if(primes[ptr]*primes[ptr] > a){
            break;
        }
        while(a%primes[ptr]==0){
            cnt++;
            a/=primes[ptr];
        }
        ptr++;
    }
    if(a>1){
        cnt++;
    }
    return cnt;
}

void solve()
{
    ll a,b,k;
    cin>>a>>b>>k;

    map<ll,ll> mp1, mp2;

    ll cnt1 = cntPrimes(a);
    ll cnt2 = cntPrimes(b);

    // trace(a);
    ll total_cnt = cnt1 + cnt2;
    
    // trace(cnt1,cnt2);

    if(k==1){
        if(a==b){
            cout<<"NO\n";
        }
        else if(a%b == 0 || b%a==0 ){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }else{
        if(k<=total_cnt){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}

void init_primes(){
    ll high = 35000;
    ll vis[high] = {0};
    for(ll i=2; i<high; i++){
        if(vis[i]==0){
            primes.PB(i);
        }
        vis[i] = 1;
        for(ll j=i*2; j<high; j+=i){
            vis[j] = 1;
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

    init_primes();
    // for(int i=0; i<10; i++){
    //     cout<<primes[i]<<" ";
    // }
    // cout<<"\n";

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}