#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fri(i, a, b) for (ll i = a; i < b; i++)
#define frd(i, a, b) for (ll i = a; i >= b; i--)
#define g(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / g(a, b)
#define lb(v, key) lower_bound(v.begin(), v.end(), key)
#define ub(v, key) upper_bound(v.begin(), v.end(), key)
#define srtvec(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())
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

long long max3(long long a, long long b, long long c)
{
    if (a > b)
        return (a > c) ? a : c;
    else
        return (b > c) ? b : c;
}

long long min3(long long a, long long b, long long c)
{
    if (a < b)
        return (a < c) ? a : c;
    else
        return (b < c) ? b : c;
}

void dancemoves()
{
    int n, m;
    cin >> n >> m;
    if (n <= m)
    {
        n = abs(n - m);
        if (n & 1)
            cout << (n / 2 + 2) << endl;
        else
            cout << (n / 2) << endl;
    }
    else
        cout << abs(m - n) << endl;
}

void minlcm1()
{
    ll a, b;
    cin >> a >> b;
    ll p = a * b;
    ll mx = p * (p - 1);
    ll mn = 2 * a;
    cout << mn << " " << mx << endl;
}

void rrr()
{
    ll n, k;
    cin >> n >> k;
    ll ans = (2 * n - k - 1) / 2;
    cout << ans * 2 << endl;
}

void eqbeauty()
{
    ll n, k, ans1 = 0, ans2 = 0, d2, d1, m = INT_MAX;
    cin >> n;
    vector<int> a(n);
    fri(i, 0, n) cin >> a[i];
    srtvec(a);
    ll l = 1, r = n - 2;
    if (n == 2)
    {
        cout << 0 << endl;
        return;
    }
    else if (n == 3)
    {
        cout << min(a[1] - a[0], a[2] - a[1]) << endl;
        return;
    }
    fri(i, 0, n - 1) ans1 += abs(a[i] - a[(n - 1) / 2]);
    fri(i, 1, n) ans2 += abs(a[i] - a[1 + (n - 1) / 2]);
    m = min(ans1, ans2);

    while (l < r)
    {
        d2 = a[n - 1] - a[l], d1 = a[r] - a[0];
        m = min(m, abs(d1 - d2));
        if (d1 < d2)
            l++;
        else
            r--;
    }
    cout << m << endl;
}

void binflip()
{
    ll n, k;
    cin >> n >> k;
    if (k == 0)
    {
        cout << "YES" << endl;
        cout << 0 << endl;
        return;
    }
    ll x = 0;
    ll k3 = k;
    while ((k3 >> 1) > 0)
    {
        x++;
        k3 = k3 >> 1;
    }
    ll start = 1, finish = k;
    vector<ll> ans;
    while (x >= 0)
    {
        ll segment_length = (1ll << x);
        x--;
        if (finish - start + 1 >= segment_length)
        {
            ans.push_back(start);
            start += segment_length;
        }
        else
        {
            ll start1 = start;
            start -= (segment_length - (finish - start + 1));
            ans.push_back(start);
            finish -= ((finish - start1 + 1));
        }
        if (start > finish && x >= 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    reverse(ans);
    if (start > finish)
    {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (int child : ans)
            cout << child << endl;
    }
    else
        cout << "NO" << endl;

    //sum values nikalo
    // k dekho sum me se kisise me hai kya?
    //agar hnn to line se krte jao yes
    //otherwise try for as target sum
}

void denomination()
{
    int s2000, s500, s100, s20, goal;
    cin >> s2000 >> s500 >> s100 >> s20 >> goal;
    int sum = 0;
    sum += s2000 * 2000;
    sum += s500 * 500;
    sum += s100 * 100;
    sum += s20 * 20;
    if (sum < goal)
    {
        cout << 0 << endl;
        return;
    }
    int remain = 0;
    int ans[4] = {0};
    int m2000 = goal / 2000;
    if (m2000 > s2000)
    {
        // ans[0] = s2000;
        // remain += (m2000 - s2000) * 2000;
        cout << 0 << endl;
        return;
    }
    else
    {
        // if (m2000 < s2000)
        // {
        //     ans[0] = m2000 + 1;
        //     cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
        //     return;
        // }
        ans[0] = m2000;
    }
    goal %= 2000;
    goal += remain;
    remain = 0;

    int m500 = goal / 500;
    if (m500 > s500)
    {
        // ans[1] = s500;
        // remain += (m500 - s500) * 500;
        cout << 0 << endl;
        return;
    }
    else
    {
        // if (m500 < s500)
        // {
        //     ans[1] = m500 + 1;
        //     cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
        //     return;
        // }
        ans[1] = m500;
    }
    goal %= 500;
    goal += remain;
    remain = 0;

    int m100 = goal / 100;
    if (m100 > s100)
    {
        // ans[2] = s100;
        // remain += (m100 - s100) * 100;
        cout << 0 << endl;
        return;
    }
    else
    {
        // if (m100 < s100)
        // {
        //     ans[2] = m100 + 1;
        //     cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
        //     return;
        // }
        ans[2] = m100;
    }
    goal %= 100;
    goal += remain;
    remain = 0;

    int m20 = goal / 20;
    if (m20 > s20)
    {
        // ans[3] = s20;
        // remain += (m20 - s20) * 20;
        cout << 0 << endl;
        return;
    }
    else
        ans[3] = m20;
    goal %= 20;
    goal += remain;
    if (goal != 0 && s20 <= m20)
    {
        cout << 0 << endl;
        return;
    }
    else if (goal != 0 && s20 > m20)
        ans[3]++;
    cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        //dancemoves();
        //minlcm1();
        //rrr();
        //eqbeauty();
        //denomination();
        binflip();
    }
    return 0;
}
