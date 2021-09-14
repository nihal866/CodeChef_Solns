#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, q;
    cin>>n>>q;
    long long arr;
    vector<long long> v;
    v.reserve(200000);
    for(int i = 0; i < n; i++){
        cin>>arr;
        v.push_back(arr);
    }
    sort(v.begin(), v.end());
    while(q--){
        long long m;
        int val;
        cin>>m;
        int l = 0, r = n-1;
        while(l <= r){
            if((m < v[0]) || m > v[n-1]){
                val = 1;
                break;
            }
            if(l == r && v[l] != m){
                int d = n - l - 1;
                val = pow(-1, d);
                break;
            }
            int mid = (l+r) / 2;
            if(m > v[mid])
                l = mid;
            else if(m < v[mid])
                r = mid;
            else if(m == v[mid]){
                val = 0;
                break;
            }
        }
        if(val == 1)
            cout<<"POSITIVE"<<endl;
        if(val == -1)
            cout<<"NEGATIVE"<<endl;
        if(val == 0)
            cout<<0<<endl;
    }

    return 0;
}
