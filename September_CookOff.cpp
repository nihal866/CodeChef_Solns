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


void adjhate(){
    int n, odd = 0, even = 0;
    cin>>n;
    ll arr[n], sum = 0;
    fri(i, 0, n){
        cin>>arr[i];
        if(arr[i] % 2)  odd++;
        else    even++;
    }
    if(even==n || odd==n){
        cout<<-1<<endl;
        return;
    }
    fri(i, 1, n){
        sum += abs(arr[i] - arr[i-1]);
    }
    if(sum % 2){
        fri(i, 0, n){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    else{
        fri(i, 0, n){
            if(arr[i]%2)    cout<<arr[i]<<" ";
        }
        fri(i, 0, n){
            if(arr[i]%2 == 0)    cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

void solve(){
    ll n;
   
    //array of arr
    cin>>n;
    vector<ll> arr(n);
    fri(i,0,n)  cin>>arr[i];
    if(n>4){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    fri(i,0,n){
        if(i%4==0)
            cout<<arr[i]<<" 0\n";
        else if(i%4==1)
            cout<<"0 "<<arr[i]<<endl;
        else if(i%4==2)
            cout<<-arr[i]<<" 0\n";
        else
            cout<<"0 "<<-arr[i]<<endl;
    }
}

void hfseq(){
    ll n;
    cin>>n;
    ll val, odd = 0, total = 0;
    fri(i, 0, n){
        cin>>val;
        if(val % 2 == 0){
            total++;
            val = val/2;
            if(val % 2) odd++;
        }
    }
    if(total >= (n+1)/2){
        if(odd >= 1){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        //adjhate();
        //hfseq();
        solve();
    }
    return 0;
}

