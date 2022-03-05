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


ll max3(ll a, ll b, ll c){
    if(a > b)
        return (a > c) ? a : c;
    else
        return (b > c) ? b : c;
}


ll min3(ll a, ll b, ll c){
    if(a < b)
        return (a < c) ? a : c;
    else
        return (b < c) ? b : c;
}


void goodweat(){
    int a, d = 7, r = 0, s = 0;
    while(d--){
        cin>>a;
        if(a)   s++;
        else    r++;
    }
    cout<<((s>r)? "YES" : "NO")<<endl;
}

void makediv3(){
    int n;
    cin>>n;
    ll m = n*3;
    if(m%9 == 0){
        fri(i, 1, n)    cout<<3;
        cout<<9<<endl;
    }
    else{
        fri(i, 0, n)    cout<<3;
        cout<<endl;
    }
}

void maxpoint(){
    ll n = 60, sum = 240, wt[60], val[60], a, b, c, x, y, z;
    cin>>a>>b>>c>>x>>y>>z;
    fri(i, 0, 20)   wt[i]=a,    val[i]=x;
    fri(i, 20, 40)  wt[i]=b,    val[i]=y;
    fri(i, 40, 60)  wt[i]=c,    val[i]=z;
    ll dp[n+1][sum+1];
    mem(dp, 0);
    fri(i, 1, n+1){
        fri(j, 1, sum+1){
            if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else    dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][sum]<<endl;
}

void spath3(){
    ll n, m, x, y;
    cin>>n>>m>>x>>y;
    ll ans = (n+m-2)*x;
    ll ans1 = (min(n, m)-1)*y;
    ll ans2 = ans1;
    ans1 += abs(n-m)*x;
    if(n%2 == m%2){
        ans2 += abs(n-m)*y;
    }
    else{
        ans2 += (abs(n-m)-1)*y;
        ans2 += x;
    }

    cout<<min3(ans, ans1, ans2)<<"\n";
}

void kbalance(){
    ll n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll ans = 0;
    set<ll> st;
    fri(i, 0, n){
        if(s[i]=='1')   st.insert(i);
    }
    fri(i, 0, n){
        if(s[i] == '1'){
            if(st.find(i-k)==st.end() && st.find(i+k)==st.end())    ans++,  st.insert(i+k);
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        //goodweat();
        //makediv3();
        //maxpoint();
        spath3();
        //kbalance();
    }
    return 0;
}