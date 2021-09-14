#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int t;
    vector<long long> v;
    v.reserve(1000000);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long nu;
        for(int i = 0; i < n; i++){
            cin>>nu;
            v.push_back(nu);
        }
        sort(v.begin(), v.end(), greater<long>());
        long long m = (v[0]*v[1]) + v[0] - v[1];
        long long k = (v[v.size() - 1]*v[v.size() - 2]) + v[v.size() - 1] - v[v.size() - 2];
        cout<<max(m ,k)<<endl;
        v.clear();
    }
    return 0;
}
