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
set<int> primes;


void preCalculatorPrime(){
    fill(isPrime+2, isPrime+N, true);
    for(int i = 2; i*i < N; i++){
        for(int j = i*i; j < N; j=j+i)
            isPrime[j] = false;
    }
    for(int i = 2; i < N; i++){
        if(isPrime[i])
            primes.insert(i);
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


void misssum(){
        int n;
        cin>>n;
        int i = 1;
        while(n--){
            cout<<i<<" ";
            i += 2;
        }
        cout<<endl;
    
}

void alldiv3(){
    int n;
    cin>>n;
    ll arr[n], sum = 0, count = 0, c1 = 0, c2 = 0;
    fri(i, 0, n){
        cin>>arr[i];
        if(arr[i] % 3){
            if(arr[i] % 3 == 1) c1++;
            else    c2++;
            count++;
            sum += arr[i];
        }
    }
    if(sum%3){
        cout<<-1<<endl;
        return;
    }
    if(count == 0){
        cout<<0<<endl;
        return;
    }
    ll ans = max(c1, c2) - min(c1, c2);
    ans -= ans/3;
    ans += min(c1, c2);

    cout<<ans<<endl;
}

void prdtpain(){
    ll n;
    cin>>n;
    ll arr[n];
    fri(i, 0, n)    cin>>arr[i];
    ll ans=0;
    for(ll i=0;i<n;i++){
        ll mx=arr[i],mn=arr[i];
        set<ll> s;
        for(ll j=i;j<n;j++){
            s.insert(arr[j]);
            mx=max(mx,arr[j]);
            mn=min(mn,arr[j]);
            if(j-i<2)
                continue;
            ll val=0;
            auto pos=s.lower_bound((mx+mn)/2);
            if(pos!=s.end()){
                val=max(val, (mx-(*pos))*((*pos)-mn));
            }
            if(pos!=s.begin()){
                pos--;
                val=max(val,(mx-(*pos))*((*pos)-mn));
            }
            ans+=val;
        }

    }
    cout<<ans<<endl;
}

void dessubk(){
    int n, k, count;
     vector<int> arr ;
     map<int,int> mp;
     cin>>n>>k;
     int no;
     count=0;
     for(int i=0;i<n;i++)
     {
         cin>>no;
         arr.push_back(no);
     }
     sort(arr.begin(),arr.end());
     for(int i=0;i<n;i++)
     {
         mp[arr[i]]++;
         
     }
     int f=0;
     for(auto m: mp)
     {
         
         if(m.second>k)
         {
             
             f=1;
             break;
         }
         
     }
     
     if(f==1)
     {
         cout<<"-1"<<endl;
     }
     else{
     reverse(arr.begin(),arr.end());
     if(k==1)
     {
         for(int i=0;i<n;i++)
         {
             cout<<arr[i]<<" ";
         }
         cout<<endl;
         continue;
     }
     reverse(arr.begin(),arr.begin()+k);
     for(int i=0;i<n;i++)
         {
             cout<<arr[i]<<" ";
         }
         cout<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    preCalculatorPrime();
    while(t--){
        //misssum();
        //alldiv3();
        //prdtpain();
        dessubk();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  // your code goes here
  int t, n,k,count;
  cin>>t;
  while (t--)
  {
     vector<int> arr ;
     map<int,int> mp;
     cin>>n>>k;
     int no;
     count=0;
     for(int i=0;i<n;i++)
     {
         cin>>no;
         arr.push_back(no);
     }
     sort(arr.begin(),arr.end());
     for(int i=0;i<n;i++)
     {
         mp[arr[i]]++;
         
     }
     int f=0;
     for(auto m: mp)
     {
         
         if(m.second>k)
         {
             
             f=1;
             break;
         }
         
     }
     
     if(f==1)
     {
         cout<<"-1"<<endl;
     }
     else{
     reverse(arr.begin(),arr.end());
     if(k==1)
     {
         for(int i=0;i<n;i++)
         {
             cout<<arr[i]<<" ";
         }
         cout<<endl;
         continue;
     }
     reverse(arr.begin(),arr.begin()+k);
     for(int i=0;i<n;i++)
         {
             cout<<arr[i]<<" ";
         }
         cout<<endl;
  }
  }
  return 0;
}
Ye wala shi hai