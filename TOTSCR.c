#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int t, n, k, sum;
    vector<long long> v;
    vector<long long> b;
    v.reserve(1000005);
    b.reserve(1000005);
    cin>>t;
    while(t--){
        cin>>n>>k;
        long long num;
        string s;
        for(int i = 0; i < k; i++){
            cin>>num;
            v.push_back(num);
        }
        for(int i = 0; i < n; i++){
            cin>>s;
            sum = 0;
            for(int j = 0; j < k; j++)
                sum += v[j] * (s[j] - '0');
            b.push_back(sum);
        }
        for(int i = 0; i < n; i++){
            cout<<b[i]<<endl;
        }
    }

    return 0;
}
