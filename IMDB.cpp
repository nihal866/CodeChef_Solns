#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    vector<long> v;
    v.reserve(100000);
    int t;
    cin>>t;
    while(t--){
        long n, x;
        cin>>n>>x;
        for(int i = 0; i < n; i++){
            long s, r;
            cin>>s>>r;
            if(s<=x)
                v.push_back(r);
        }
        sort(v.begin(), v.end(), greater<long>());
        cout<<v[0]<<endl;
        v.clear();
    }

    return 0;
}
