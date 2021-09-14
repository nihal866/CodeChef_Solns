#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fri(i, a, b) for (int i = a; i < b; i++)
#define frd(i, a, b) for (int i = a; i >= b; i--)
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

void savkono()
{
    ll n, z;
    priority_queue<ll> pq;
    cin >> n >> z;
    ll arr[n], sum = 0;
    fri(i, 0, n)
    {
        cin >> arr[i];
        pq.push(arr[i]);
        sum += arr[i];
    }
    ll moves = 0, nw;
    while (1)
    {
        nw = pq.top();
        if (nw == 0 && z > 0)
        {
            cout << "Evacuate" << endl;
            return;
        }
        z -= nw;
        moves++;
        if (z <= 0)
        {
            cout << moves << endl;
            return;
        }
        pq.pop();
        pq.push(nw / 2);
    }
}

void cvote()
{
    int n, m;
    cin >> n >> m;
    map<string, string> iden;
    string a, b;
    fri(i, 0, n)
    {
        cin >> a >> b;
        iden.insert({a, b});
    }
    map<string, int> country;
    map<string, int> emails;
    string ansC, ansE;
    fri(i, 0, m)
    {
        cin >> a;
        emails[a]++;
        country[iden[a]]++;
    }
    int mn = INT_MIN;
    for (auto ns : emails)
    {
        if (ns.second > mn)
        {
            mn = ns.second;
            ansE = ns.first;
        }
    }
    mn = INT_MIN;
    for (auto cs : country)
    {
        if (cs.second > mn)
        {
            mn = cs.second;
            ansC = cs.first;
        }
    }
    cout << ansC << endl
         << ansE << endl;
}

void dpairs(){
    int n, m;
    cin>>n>>m;
    ll mn = 10000000000, mx = -10000000000, a, ind1, ind2;
    fri(i, 0, n){
        cin>>a;
        if(a < mn){
            mn = a;
            ind1 = i;
        }
    }
    fri(i, 0, m){
        cin>>a;
        if(a > mx){
            mx = a;
            ind2 = i;
        }
    }
    fri(i, 0, m){
        cout<<ind1<<" "<<i<<endl;
    }
    fri(i, 0, n){
        if(i == ind1)   continue;
        cout<<i<<" "<<ind2<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        //savkono();
        //cvote();
        dpairs();
    }
    return 0;
}