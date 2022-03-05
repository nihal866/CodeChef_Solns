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


void n1values(){
    int n;
    cin>>n;
    ll a = 1;
    cout<<a<<" ";
    fri(i, 0, n)    cout<<(a << i)<<" ";
    cout<<endl;
}

void chefcar(){
    ll n, v;
    cin>>n>>v;
    ll mx = (n*(n-1))/2;
    cout<<mx<<" ";
    if(v >= (n-1)){
        cout<<(n-1)<<endl;
        return;
    }
    n = n-v;
    ll cost = v-1;
    cost += ((n+1)*n)/2;
    cout<<cost<<endl;
}

void maximgcd(){
    ll n, a;
    cin>>n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    fri(i, 0, n)    cin>>a, pq.push(a);
    a = pq.top();
    pq.pop();
    ll b = pq.top();
    pq.pop();
    ll lg = a*b;
    while(!pq.empty()){
        lg = g(pq.top(), lg);
        pq.pop();
    }
    cout<<lg<<endl;
}

vector<ll> v;
bool isvalid(ll ans,ll n,ll k){ll upper=n/2;
// cout<<ans;
         ll sum= v[ans-1];ll cur=ans+1;
         fri(i,1,n){
                  if( i*n+(upper*(n-i))+1<cur)return 0;
                int k=max((i+1)*(upper+1),cur);  sum+=v[k-1];
           cur=k+1;
         //   cout<<k<<" ";
         }
         // cout<<"sum"<<sum<<endl;
         return sum<=k;
}
void medmax(){
    ll n, f;
    cin>>n>>f;
    ll arr[n][n];
    
    fri(i, 0, n){
        fri(j, 0, n){
            cin>>arr[i][j];
            v.push_back(arr[i][j]);
        }
    }
    srtvec(v);
    ll ans = -1;
    ll upper=n/2; ll s=upper+1,e=n*upper+1;
         while(s<=e){
                  ll mid=s+(e-s)/2;
                  if(isvalid(mid,n,f)){
                           ans=v[mid-1];s=mid+1;
                  }else e=mid-1;
         }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        //n1values();
        //chefcar();
        //maximgcd();
        medmax();
    }
    return 0;
}