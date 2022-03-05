#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
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


int max3(int a, int b, int c){
    if(a > b)
        return (a > c) ? a : c;
    else
        return (b > c) ? b : c;
}


int min3(int a, int b, int c){
    if(a < b)
        return (a < c) ? a : c;
    else
        return (b < c) ? b : c;
}


void vaccinq(){
    int n, p, x, y, ans = 0;
    cin>>n>>p>>x>>y;
    int arr[n];
    fri(i, 0, n){
        cin>>arr[i];
    }
    fri(i, 0, p){
        if(arr[i])  ans += y;
        else    ans += x;
    }
    cout<<ans<<endl;
}

void diwali1(){
    ll p,a,b,c,x,y, anar, chak;
    cin>>p>>a>>b>>c>>x>>y;
    
    anar=(a*x)+b;
    chak=(a*y)+c;
    ll ans = min(anar,chak);
     
    ll res = p/ans;
    cout<<res<<"\n";
}

void magdoors(){
    int n;
    string s;
    cin>>s;
    n = s.size();
    int ans = 0;
    fri(i, 0, n){
        if((s[i]-'0') != (ans+1)%2) ans++;
    }
    cout<<ans<<endl;
}

void addndiv(){
    ll m,n;
    cin>>m>>n;
    ll hf = __gcd(m,n);
    m= m/hf;
    for(int i=2; i*i <= m; i++){
        if(m%i==0)
        { 
            if(n%i!=0)
            {
                cout<<"NO\n";
                return;
            }
            while(m%i==0){
                m/=i;
            }
        }
    }
    if(n%m!=0)
    {
        cout<<"NO\n";
        return;  
    }
    cout<<"YES\n";
}

void swapgame(){
        ll n, val;
        cin>>n;
        vector<ll> a, b;
        a.reserve(n);
        b.reserve(n);
        fri(i, 0, n)    cin>>val,   a.push_back(val);
        fri(i, 0, n)    cin>>val,   b.push_back(val);
        ll temp = a[n-1];
        ll s = 1;
        frd(i, n-2, 0){
            ll tempp=temp+a[i];
            a[i]=s*a[i]-temp;
            temp=tempp;
            s++;
        }
        temp=b[n-1];
        s = 1;
        frd(i, n-2, 0){
            ll tempp=temp+b[i];
            b[i]=s*b[i]-temp;
            temp=tempp;
            s++;
        }
        ll ans=0;
        a[n-1]=0;
        b[n-1]=0;
        fri(i, 0, n){
            ans+=a[i];
            ans-=b[i];
        }
        cout<<ans/2<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        //vaccinq();
        //magdoors();
        //addndiv();
        //diwali1();
        swapgame();
    }
    return 0;
}
