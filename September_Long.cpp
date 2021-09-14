#include<bits/stdc++.h>
using namespace std;
#define ll long long
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

//Problem A starts
void airline(){
    int a, b, c, d, e;
    cin>>a>>b>>c>>d>>e;
    int mx, mid, mn;
    mx = max3(a, b, c);
    mn = min3(a, b, c);
    mid = a^b^c^mn^mx;
    if(((a+b)<=d && c<=e) || ((a+c)<=d && b<=e) || ((c+b)<=d && a<=e))  cout<<"YES"<<endl;
    else    cout<<"NO"<<endl;
    return;
}//Problem A ends

//Problem B starts
void travelps(){
    int n, a, b, count = 0;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    fri(i, 0, n){
        if(s[i] == '0') count+=a;
        else    count+=b;
    }
    cout<<count<<endl;
}//Problem B ends

//Problem C starts
void shufflin(){
    int n, e = 0, o = 0, diff, sum = 0;
    cin>>n;
    int arr[n];
    fri(i, 0, n){
        cin>>arr[i];
        if(arr[i] % 2)  o++;
        else    e++;
    }
    if(n%2){
        if(e <= (n+1)/2)    diff=e;
        else    diff=(n+1)/2;
        sum += diff;
        if(o <= n/2)    diff = o;
        else    diff = n/2;
        sum += diff;
    }
    else{
        if(e <= n/2)    diff=e;
        else    diff=n/2;
        sum += diff;
        if(o <= n/2)    diff = o;
        else    diff = n/2;
        sum += diff;
    }
    cout<<sum<<endl;
}//Problem C ends

//Problem D starts
void palint(){
    int n, x;
    cin>>n>>x;
    int arr[n], a[n];
    map<int, int> mp1, mp2;
    set<int> st;
    int mx = 0;
    fri(i, 0, n){
        cin>>arr[i];
        a[i] = arr[i]^x;
        mp1[arr[i]]++;
        mp2[a[i]]++;
    }
    int moves = 0, sum;
    fri(i, 0, n){
        sum = mp1[arr[i]];
        if(x!=0 && (mp2.find(arr[i]) != mp2.end()))   sum+=mp2[arr[i]];
        if(sum == mx)   moves = min(moves, mp2[arr[i]]);
        else if(sum > mx){
            mx = sum;
            moves = (x!=0)?mp2[arr[i]]:0;
        }
    }
    cout<<mx<<" "<<moves<<endl;
}//Problem D ends

//Problem E starts
ll count(ll a, ll b, ll x[], ll y[], int n){
    ll moves = 0;
    fri(i, 0, n){
        ll ax = a - x[i];
        ll by = b - y[i];
        if(ax==0 && by==0)  continue;
        if((!ax && by) || (ax && !by) || (abs(ax)==abs(by)))    moves++;
        else    moves+=2;
    }
    return moves;
}

void pointmee(){
    int n;
    cin>>n;
    ll x[n], y[n];
    fri(i, 0, n)    cin>>x[i];
    fri(j, 0, n)    cin>>y[j];
    ll mn = INT_MAX, a, b,si, sj;
    fri(i, 0, n){
        fri(j, 0, n){
            a = (x[i]+x[j])/2;
            b = (y[i]+y[j])/2;
            mn = min(mn, count(a, b, x, y, n));
            a = x[i];
            b = y[j];
            mn = min(mn, count(a, b, x, y, n));
            si = x[i]+y[i];
            sj = x[j]+y[j];
            a = (si + sj)/2;
            b = (si - sj)/2;
            mn = min(mn, count(a, b, x, y, n));
            si = x[i]+y[i];
            a = x[j];
            b = si-a;
            mn = min(mn, count(a, b, x, y, n));
            sj = x[i]+y[i];
            b = y[j];
            a = sj-b;
            mn = min(mn, count(a, b, x, y, n));
            si = x[i]-y[i];
            a = x[j];
            b = a-si;
            mn = min(mn, count(a, b, x, y, n));
            sj = x[i]-y[i];
            b = y[j];
            a = sj-b;
            mn = min(mn, count(a, b, x, y, n));
        }
    }
    cout<<mn<<endl;
}//Problem E ends

//Problem F starts
void mindigsum(){
    ll n, l, r, m;
    cin>>n>>l>>r;
    ll ans = INT_MAX, ans1, base;
    if(n>=l && n<=r){
        cout<<n<<endl;
        return;
    }
    if(n < l){
        cout<<l<<endl;
        return;
    }
    ll z = sqrt(l);
    l = max(l, z);
    frd(i, r, l){
        ans1 = 0, m = n;
        while(m>0){
            ans1 += m%i;
            m = m/i;
            if(ans1 > ans)  break;
        }
        if(ans1 < ans){
            base = i;
            ans = ans1;
        }
        if(ans == 1)    break;
    }
    cout<<base<<endl;
}//Problem F ends

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        //airline();
        //travelps();
        //shufflin();
        //palint();
        //pointmee();
        mindigsum();
    }
    return 0;
}