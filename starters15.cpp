#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fri(i, a, b) for (ll i = a; i < b; i++)
#define frd(i, a, b) for (ll i = a; i >= b; i--)
#define g(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / g(a, b)
#define lb(v, key) lower_bound(v.begin(), v.end(), key)
#define ub(v, key) upper_bound(v.begin(), v.end(), key)
#define srtvec(v) sort(v.begin(), v.end())
#define srt(arr, n) sort(arr, arr + n)
#define mem(arr, key) memset(arr, key, sizeof(arr))

const int N = 1000000;
bool isPrime[N];
set<int> s;

void preCalculatorPrime()
{
    fill(isPrime + 2, isPrime + N, true);
    for (int i = 2; i * i < N; i++)
    {
        for (int j = i * i; j < N; j = j + i)
            isPrime[j] = false;
    }
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
            s.insert(i);
    }
}

const long long M = 1e9 + 7;
long long mod(long long x)
{
    return ((x % M + M) % M);
}

long long add(long long a, long long b)
{
    return mod(mod(a) + mod(b));
}

long long mul(long long a, long long b)
{
    return mod(mod(a) * mod(b));
}

int max3(int a, int b, int c)
{
    if (a > b)
        return (a > c) ? a : c;
    else
        return (b > c) ? b : c;
}

int min3(int a, int b, int c)
{
    if (a < b)
        return (a < c) ? a : c;
    else
        return (b < c) ? b : c;
}

void npairs()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<int, int> mp1, mp2;
    fri(i, 0, n)
    {
        mp1[(s[i] - '0') - i]++;
        mp2[(s[i] + '0') + i]++;
    }
    ll res = 0, cnt;
    for (auto m : mp1)
    {
        cnt = m.second;
        res += ((cnt - 1) * cnt) / 2;
    }
    for (auto m : mp2)
    {
        cnt = m.second;
        res += ((cnt - 1) * cnt) / 2;
    }
    cout << res << endl;
}

void diveo()
{
    int n, a, b;
    cin >> n >> a >> b;
    int od = 0, ev = 0;
    int ans = 0;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            n /= i;
            if (i % 2)
                od++;
            else
                ev++;
        }
    }
    if (n > 1)
    {
        if (n % 2)
            od++;
        else
            ev++;
    }
    if (a >= 0 && b >= 0)
    {
        cout << a * ev + b * od << endl;
        return;
    }
    else if (a >= 0 && b < 0)
    {
        if (ev)
            ans = a * ev;
        else if (od)
            ans = b;
    }
    else if (a < 0 && b >= 0)
    {
        ans = b * od;
        if (ev)
            ans += a;
    }
    else if (a < 0 && b < 0)
    {
        if (ev)
            ans += a;
        else if (od)
            ans += b;
    }
    cout << ans << endl;
}

void mydiveo()
{
    ll n, a, b, k;
    cin >> n >> a >> b;
    k = n;
    ll ans = 0;
    if (a >= 0)
    {
        while (n % 2 == 0)
        {
            ans += a;
            n /= 2;
        }
    }
    if (b <= 0)
    {
        if (n == k)
        {
            if (n & 1)
                cout << b << endl;
            else
                cout << a << endl;
            return;
        }
        ans += b;
        cout << ans << endl;
        return;
    }
    for (ll i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            n = n / i;
            ans += b;
        }
    }
    if (n > 1)
    {
        if (n & 1)
            ans += b;
        else
            ans += a;
    }
    cout << ans << endl;
}

void minsz()
{
    ll n;
    cin >> n;
    ll c = 64 - __builtin_clzll(n);
    ll curr = (1LL << c) - 1LL;
    vector<ll> v;
    v.push_back(curr);
    for (ll i = 63; i >= 0; i--)
    {
        if (((1LL << i) & curr) != ((1LL << i) & n))
        {
            v.push_back((1LL << (i + 1LL)) - 1LL);
            curr ^= ((1LL << (i + 1LL)) - 1LL);
        }
    }
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void intconca(){
    int n,l,r,cnt=0;
    string s,str,p,g;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=i;j<n;j++){
        p = "";
        p += to_string(a[i]);
        p += to_string(a[j]);
        if(l<=stoi(p)<=r){
            cnt++;
        }
        if(j>i){
            reverse(p.begin(),p.end());
            g += p;
            if(l<=stoi(g)<=r) {
                cnt++;
            }
        }
        }
    }
    cout<<cnt<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        //npairs();
        //diveo();
        //minsz();
        intconca();
    }
    return 0;
}
