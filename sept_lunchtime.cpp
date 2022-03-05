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
long long INF =1000000000000000000;
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


void unqeq(){
    ll n;
    cin>>n;
    vector<int> first;
    vector<int> second(n/2);
    ll sum = (n*(n+1))/2;
    ll f = 0,s = (n/2)-1;
    if(sum%2 != 0) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        ll start = 1,end = n;
        bool flag = true;
        while(start<=end){
            if(flag == true){
                flag = false;
                first.push_back(start);
                first.push_back(end);
                }
                else{
                    flag  = true;
                    second[f]=start;
                    f++;
                    second[s] = end;
                    s--;
                    }
                    start++;
                    end--;
            }
            for(auto it : first) cout<<it<<" ";
            cout<<endl;
            for(auto it : second) cout<<it<<" ";
            cout<<endl;
        }
    return;
}

void sod(){
    ll l, r, d = 3;
    cin>>l>>r;
    if (l%3 == 0)   cout<<(r / d) - (l/d) + 1<<endl;
    else    cout<<(r/d) - (a/d)<<endl;
}

bool check(int n)
{
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
        return 0;
    }
    return 1;
}

void intrep(){
    ll n;
    cin>>n;
    if(n%2==0){
        cout<<2*n<<" "<<n<<endl;
        continue;
    }
    for(int i=3;i<100;i++){
        if(check(i)&&n%i!=0){
            cout<<i*n<<" "<<(i-1)*n<<endl;
            break;
        }
    }
}

struct mycmp
{
    bool operator()(pair<int,int>a,pair<int,int>b)const
    {
        return (a.first<b.first) || (a.first==b.first && a.second>b.second);
    }
};

void alboface(){
    ll n;
    cin>>n;
    if(n==1)    cout<<"Alice\n";
    else{
        if(n&1)
        {
            n=n-1;
            ll cnt=0;
            while(n)
            {
                ll cnt1=0;
                while(n%2==0)
                n=n/2,++cnt1;
                n=n-1;
                if(cnt1>=2)
                ++cnt;
            }
            if(cnt>=2)
            cout<<"Bob\n";
            else
            {
                if(cnt==0)
                cout<<"Alice\n";
                else
                cout<<"Bob\n";
            }
            }
            else
            {
                ll cnt=0;
                while(n)
                {
                    ll cnt1=0;
                    while(n%2==0)
                    n=n/2,++cnt1;
                    n=n-1;
                    if(cnt1>=2)
                    ++cnt;
                }
                if(cnt>=2)
                cout<<"Alice\n";
                else
                {
                    if(cnt==0)
                    cout<<"Bob\n";
                    else
                    cout<<"Alice\n";
                }
            }
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        //unqeq();
        //sod();
        intrep();
        //alboface();
    }
    return 0;
}
