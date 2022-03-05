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
#define reverse(v) reverse(v.begin(), v.end())
#define srt(arr,n) sort(arr, arr+n)
#define mem(arr,key) memset(arr, key, sizeof(arr))


// vector<ll> prime(10000000, 1);
// vector<ll> v(10000000, 0);


// void preCalculatorPrime(){
//     prime[0] = 0;
//     prime[1] = 0;
//     for(ll i = 2; i*i <= 1e7; i++){
//         if(prime[i]){
//             for(ll j = i*i; j <= 1e7; j+=i) prime[j] = 0;
//         }
//     }
//     for(ll i = 2; i <= 1e7; i++){
//         v[i] = v[i-1] + prime[i];
//     }
// }

// const int N = 10000005;
// bool isPrime[N];
// vector<ll> primes;


// void preCalculatorPrime(){
//     fill(isPrime+2, isPrime+N, true);
//     for(int i = 2; i*i < N; i++){
//         for(int j = i*i; j < N; j=j+i)
//             isPrime[j] = false;
//     }
//     for(int i = 2; i < N; i++){
//         if(isPrime[i])
//             primes.push_back(i);
//     }
// }



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


void passorfail(){
    int n, x, p;
    cin>>n>>x>>p;
    n = n - x;
    x = x*3;
    x -= n;
    if(x >= p)  cout<<"PASS"<<endl;
    else    cout<<"FAIL"<<endl;
}

void hcagmam1(){
    ll x, y;
    cin>>x>>y;
    string s;
    cin>>s;
    ll o = 0, streak = 0, ans = 0;
    fri(i, 0, s.size()){
        if(s[i] == '1') o++,    streak++;
        else{
            ans = max(ans, streak);
            streak = 0;
        }
    }
    ans = max(ans, streak);
    ll res = ans*y + o*x;
    cout<<res<<endl;
}

void directn(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll l = 0, lans = 0, r = 0, rans = 0;
    fri(i, 0, n){
        if(s[i] == 'L'){
            l++;
            rans = max(rans, r);
            r = 0;
        }
        else{
            r++;
            lans = max(lans, l);
            l = 0;
        }
    }
    if(lans>=2 || rans>=2)  cout<<"YES"<<endl;
    else    cout<<"NO"<<endl;
}

const ll MAX_SIZE = 10000005;
vector<ll>isprime(MAX_SIZE , true);
vector<ll>prime;
vector<ll>SPF(MAX_SIZE);
void manipulated_seive(ll N)
{
    isprime[0] = isprime[1] = false ;
    for (long long int i=2; i<N ; i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
            SPF[i] = i;
        }
        for (long long int j=0;
             j < (int)prime.size() &&
             i*prime[j] < N && prime[j] <= SPF[i];
             j++)
        {
            isprime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}

void chefmgx(){
    ll x, y, a = 1e7 + 1;
    cin>>x>>y;

    if(y-x == 1){
        cout<<1<<endl;
        return;
    }
    if(y-x == 2){
        if(isprime[y])  cout<<1<<endl;
        else    cout<<2<<endl;
    }
    ll ans = y-x;
    auto itr1 = lb(prime, x+2);
    auto itr2 = lb(prime, y);
    ll remove = (itr2 - itr1)+1;
    //cout<<"...."<<remove<<endl;
    if(!isprime[y]) remove--;
    cout<<ans-remove<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    // primes.reserve(1e7);
    // preCalculatorPrime();
    manipulated_seive(1e7 + 4);
    while(t--){
        passorfail();
        //hcagmam1();
        //directn();
        //chefmgx();
    }
    return 0;
}


