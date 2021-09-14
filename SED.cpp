#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
//Naive Solution as follows...
#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin>>t;
    vector<long> v;
    vector<long> v1;
    v.reserve(100000);
    v1.reserve(10000);
    while(t--){
        int n;
        cin>>n;
        long arr[n];
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                for(int k = i; k <= j; k++){
                    v.push_back(arr[k]);
                }
                sort(v.begin(), v.end(), greater<long>());
                v1.push_back(v[0] - v[1]);
                v.clear();
            }
        }
        sort(v1.begin(), v1.end());
        cout<<std::distance(v1.begin(), std::unique(v1.begin(), v1.end()))<<endl;
        v1.clear();
    }
    return 0;
}
