#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fri(i, a, b) for(ll i = a; i < b; i++)
#define frd(i, a, b) for(ll i = a; i >= b; i--)
#define g(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/g(a,b)
#define lb(v,key) lower_bound(v.begin(), v.end(), key)
#define ub(v,key) upper_bound(v.begin(), v.end(), key)
#define srtvec(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())
#define srt(arr,n) sort(arr, arr+n)
#define mem(arr,key) memset(arr, key, sizeof(arr))


const int N = 1000000;
bool isPrime[N];
set<int> s;


void preCalculatorPrime(){
    fill(isPrime+2, isPrime+N, true);
    for(int i = 2; i*i < N; i++){
        for(int j = i*i; j < N; j=j+i)
            isPrime[j] = false;
    }
    for(int i = 2; i < N; i++){
        if(isPrime[i])
            s.insert(i);
    }
}


const long long M = 1e9 + 7;
long long mod(long long x){
    return ((x%M + M)%M);
}


long long add(long long a, long long b){
    return mod(mod(a) + mod(b));
}


long long mul(long long a, long long b){
    return mod(mod(a) * mod(b));
}


long long max3(long long a, long long b, long long c){
    if(a > b)
        return (a > c) ? a : c;
    else
        return (b > c) ? b : c;
}


long long min3(long long a, long long b, long long c){
    if(a < b)
        return (a < c) ? a : c;
    else
        return (b < c) ? b : c;
}

void maxdmge(){
    int n;
    cin>>n;
    ll arr[n];
    fri(i, 0, n)    cin>>arr[i];
    cout<<(arr[0] & arr[1])<<" ";
    fri(i, 1, n-1){
        cout<<max((arr[i-1]&arr[i]), (arr[i]&arr[i+1]))<<" ";
    }
    if(n > 2)   cout<<(arr[n-2]&arr[n-1])<<" ";
    cout<<endl;
}

void gamew(){
    string s;
    int n;
    cin>>n;
    cin>>s;
    int count = 1, ans = 0;
    fri(i, 1, n){
        if(s[i] == s[i-1])  count++;
        else{
            ans++;
            count = 1;
        }
    }
    ans++;
    if(ans%3 == 2)  cout<<"RAMADHIR"<<endl;
    else    cout<<"SAHID"<<endl;
}

void dfs(vector<vector<ll>> & adj, vector<ll> & gcd, ll u, ll par){
    for(auto & a : adj[u]){
        if(a == par) continue;
        dfs(adj,gcd,a,u);
        gcd[u] = g(gcd[u],gcd[a]);
    }
}

ll res=0;

void dfs1(vector<vector<ll>> & adj, vector<ll> & gcd, ll u, ll par, ll exc, vector<ll> & arr){
    ll temp = exc;
    for(auto & to:adj[u]){
        if(to == par) continue;
        temp+=gcd[to];
    }
    res=max(res,temp);
    ll transfer = __gcd(arr[u],exc);
    ll n = adj[u].size();
    if(par!=-1){
        n--;
    }
    vector<ll> pref(n+2,transfer),suff(n+2,transfer);
    ll idx=0;
    for(auto & a:adj[u]){
        if(a == par) continue;
        idx++;
        pref[idx]= g(pref[idx],gcd[a]);
        suff[idx]= g(suff[idx],gcd[a]);
    }
    for(ll i=1;i<=n;i++){
        pref[i] = g(pref[i],pref[i-1]);
    }
    for(ll i=n;i>=1;i--){
        suff[i]= g(suff[i],suff[i+1]);
    }
    idx=0;
    for(auto & a:adj[u]){
        if(a == par) continue;
        idx++;
        ll combine = __gcd(pref[idx-1], suff[idx+1]);
        dfs1(adj,gcd,a,u,combine,arr);
    }
}

void dltnode(){
    ll n;
    cin>>n;
    res=0;
    vector<vector<ll>> adj(n);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll> gcd(arr.begin(),arr.end());
    dfs(adj,gcd,0,-1);
    dfs1(adj,gcd,0,-1,0,arr);
    cout<<res<<endl;
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        //gamew();
        //dltnode();
        gundis();
        //maxdmge();
    }
    return 0;
}

