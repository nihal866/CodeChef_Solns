#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fri(i, a, b) for(int i = a; i < b; i++)
#define frd(i, a, b) for(int i = a; i >= b; i--)
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

void bigarray(){
    ll n, s;
    cin>>n>>s;
    ll sum = (n*(n+1))/2;
    ll ans = abs(sum-s);
    if(ans>=1 && ans<=n)    cout<<ans<<endl;
    else    cout<<-1<<endl;
}

void fillgrid(){
    int n;
    cin>>n;
    if(n % 2 == 0){
        fri(i, 0, n){
            fri(j, 0, n){
                cout<<"-1 ";
            }
            cout<<endl;
        }
    }
    else{
        fri(i, 0, n){
            fri(j, 0, n){
                if(i == j)  cout<<"1 ";
                else    cout<<"-1 ";
            }
            cout<<endl;
        }
    }
}

// void posspew(){
//     int n, k;
//     cin>>n>>k;
//     int arr[n];
//     fri(i, 0, n)    cin>>arr[i];
// }

// int atmq() {

//      int n;
//      cin >> n;
//      int power[n];
//      for(int i = 0; i < n; i++) cin >> power[i];
     
//      int ans[n], index[n];
//      for(int i = 0; i < n; i++) index[i] = i;
     
//      for(int i = 0; i < n; i++){
//          ans[index[i]] = i+1;
//          for(int j = i+1; j < n-1; j++){
//              if(power[j] < power[j+1]){
//                  swap(index[j],index[j+1]);
//                  swap(power[j],power[j+1]);
//              }
//          }
         
//      }
//      for(int i = 0; i < n; i++) cout << ans[i] << " ";
//      cout << endl;
// }


long int minFriends(int numNodes, int numEdges){
    long int count = 1, n = numNodes-1, edges = numEdges;
    while(numEdges>=n && numEdges>0){
        numEdges -= n;
        n--;
        count++;
    }
    if(count==1)    return 0;
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        //bigarray();
        //fillgrid();
        int n, m;
        cin>>n>>m;
        cout<<minFriends(n, m)<<endl;
        //atmq();
    }
    return 0;
}

