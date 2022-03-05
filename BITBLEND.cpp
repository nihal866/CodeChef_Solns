#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define fri(i, a, b) for(int i = a; i < b; i++)
#define frd(i, a, b) for(int i = a; i >= b; i--)
#define g(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/g(a,b)
#define vll vector<int>
#define lb(v,key) lower_bound(v.begin(), v.end(), key)
#define ub(v,key) upper_bound(v.begin(), v.end(), key)
#define srtvec(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define srt(arr,n) sort(arr, arr+n)
#define mem(arr,key) memset(arr, key, sizeof(arr))


void print(vector<pair<int, int>> &arr){
    for(auto a : arr)   cout<<a.first<<" "<<a.second<<endl;
}
void nd(){
    int n, first_even = -1, first_odd = -1, odd, even;
    cin>>n;
    vll arr(n);
    fri(i, 0, n){
        cin>>arr[i];
        if(arr[i] & 1)  first_odd = arr[i], odd = i;
        else    first_even = arr[i],    even = i;
    }
    if(first_odd==-1 || first_even==-1){
        cout<<-1<<endl;
        return;
    }
    vector<pair<int, int>> a, b;
    //  Hoping for odd at odd places and even at even places, i.e, e 0 e 0 e 0
    fri(i, 0, n){
        if(i & 1){
            if(arr[i]&1 || i==odd)  continue;
            a.push_back({odd, i});
        }
        else{
            if(arr[i]%2==0 || i==even)  continue;
            a.push_back({even, i});
        }
    }
    //  Hoping for even at odd places ans odd at even places, i.e o e o e o e
    fri(i, 0, n){
        if(i & 1){
            if(arr[i]%2==0 || i==even)  continue;
            b.push_back({even, i});
        }
        else{
            if(arr[i]&1 || i==odd)  continue;
            b.push_back({odd, i});
        }
    }
    if(a.size() < b.size()){
        cout<<a.size()<<endl;
        print(a);
        return;
    }
    cout<<b.size()<<endl;
    print(b);
}
    
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        nd();
    }
    return 0;
}