#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        long long arr[n], net = 0;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            net = net ^ arr[i];
        }
        cout<<net<<endl;
    }

    return 0;
}
