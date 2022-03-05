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


void luckynum(){
    int a, b, c;
    cin>>a>>b>>c;
    if(a==7 || b==7 || c==7)    cout<<"Yes"<<endl;
    else    cout<<"No"<<endl;
}

void testseries(){
    int arr[5];
    int ind = 0, eng = 0;
    fri(i, 0, 5){
        cin>>arr[i];
        if(arr[i] == 1) ind++;
        else if(arr[i] == 2)    eng++;
        else    continue;
    }
    if(ind > eng)   cout<<"INDIA"<<endl;
    else if(eng > ind)  cout<<"ENGLAND"<<endl;
    else    cout<<"DRAW"<<endl;
}

void maxdistkt(){
    int n;
    cin>>n;
    ll a[n] = {0}, b[n];
    map<ll, queue<ll>> mp;
    fri(i, 0, n){
        cin>>b[i];
        mp[b[i]].push(i);
    }
    ll i = 0, temp;
    for(auto m : mp){
        //cout<<"This time: "<<m.first<<endl;
        while(!m.second.empty()){
            // cout<<"This time: "<<m.first<<" i: "<<i<<endl;
            temp = m.second.front();
            m.second.pop();
            // cout<<"This time: "<<m.first<<" temp: "<<temp<<endl;
            if(i == m.first)    i--;
            a[temp] = i;
            i++;
        }
    }
    fri(i, 0, n)    cout<<a[i]<<" ";
    cout<<endl;
}

void mindiff1(){
    int n,m;
    cin>>n>>m;
    vector<int>v[n+1];
    int arr[n+1];
    for(int i=0;i<=n;i++)   arr[i]=0;
    for(int i=0;i<m;i++)
    {
      int x,y;
      cin>>x>>y;
      v[x].push_back(y);
      v[y].push_back(x);
      arr[x]=v[x].size();
      arr[y]=v[y].size();
    }
    set<int>s;
    set<int>a1[n+1];
    for(int i=1;i<=n;i++)
    {   
       a1[arr[i]].insert(i);
       s.insert(arr[i]);
    }
    int x1=n;
    int ans=0;
    queue<int>q;
    int value[n+1];
    while(s.size()>0)
    {
      ans=max(ans,*s.begin());
      for(int child:a1[*s.begin()])
      {
        q.push(child);
      }
      a1[*s.begin()].clear();
      s.erase(s.begin());
      while(!q.empty())
      {
        int x=q.front();
        q.pop();
        value[x]=x1;
        x1--;
        for(int child:v[x])
        {
          if(arr[child]>arr[x])
          { 
            a1[arr[child]].erase(child);
            if(a1[arr[child]].size()==0)
            {
              s.erase(arr[child]);
            }
            arr[child]--;
            a1[arr[child]].insert(child);
            if(a1[arr[child]].size()==1)
              s.insert(arr[child]);
          }
        }
      }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
      cout<<value[i]<<" ";
     cout<<endl;
    return;
}

ll inf = 1e15;
ll n, m, k, N, z[100010], pi[100010], g[100010], found[100010];
void sstrpref1(){
    string s, x, t, S;
    cin>>s>>t>>x;
    ll k = x.length(), n = s.length(), m = t.length();
    for(ll i = 0; i <= max(n,m) + k + 10; i++){
        z[i] = 0, pi[i] = 0, g[i] = 0, found[i] = 0;
    }
   
    S = t + "?" + x;
    N = S.length();

    for (ll i = 1, l = 0, r = 0; i < N; ++i) {
        if (i <= r){
            z[i] = min (r - i + 1, z[i - l]);
        }
        while (i + z[i] < N && S[z[i]] == S[i + z[i]]){
            ++z[i];
        }
        if (i + z[i] - 1 > r){
            l = i, r = i + z[i] - 1;
        }
    }
    S = s + "?" + x;
    N = S.length();

    for (ll i = 1,j; i < N; i++) {
        j = pi[i-1];
        while (j > 0 && S[i] != S[j]){
            j = pi[j-1];
        }
        if (S[i] == S[j]){
            j++;
        }
         pi[i] = j;
         if(i > n){
           j = i - n;
           g[pi[i]] = max(g[pi[i]], z[j + m + 1]);
           found[pi[i]] = 1;
         }
    }
    g[0] = max(z[m + 1], g[0]);
    found[0] = 1;

    ll ans = 0;
    for(ll i = n; i >= 0; --i){
      if(!found[i]) continue;
      ans += g[i] + 1;

      found[pi[i - 1]] = 1;
      g[pi[i - 1]] = max(g[pi[i - 1]], g[i]);
    }
    cout <<ans <<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        //luckynum();
        //testseries();
        //maxdistkt();
        //mindiff1();
        sstrpref1();
    }
    return 0;
}