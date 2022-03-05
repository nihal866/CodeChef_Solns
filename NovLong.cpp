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

void equalcoin(){
    ll x, y;
    cin>>x>>y;
    if(1&x) cout<<"NO"<<endl;
    else if(x==0 && y&1)    cout<<"NO"<<endl;
    else    cout<<"YES"<<endl;
}

void hillseq(){
    ll n, a;
    cin>>n;
    map<ll, ll> mp;
    priority_queue<ll> pq;
    fri(i, 0, n){
        cin>>a;
        pq.push(a);
        mp[a]++;
    }
    deque<ll> dq;
    ll temp;
    temp = pq.top();
    if(mp[temp] > 1){
        cout<<-1<<endl;
        return;
    }
    while(!pq.empty()){
        temp = pq.top();
        if(mp[temp] > 2){
            cout<<-1<<endl;
            return;
        }
        if(mp[temp] == 2){
            dq.push_back(temp);
            dq.push_front(temp);
            pq.pop();
        }
        else if(mp[temp] == 1)  dq.push_back(temp);
        pq.pop();
    }
    fri(i, 0, n)    cout<<dq.front()<<" ",  dq.pop_front();
    cout<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        //hillseq();
        equalcoin();
    }
    return 0;
}