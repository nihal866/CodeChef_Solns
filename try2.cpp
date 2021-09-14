#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

long dp[100000];

long solve(long n, long k){
    if(n == 1)
        return 1;
    if(k == 0)
        return 0;
    if(dp[n] != -1)
        return dp[n];
    dp[n] = max(n^solve(n-1, k-1), solve(n-1, k));
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
        memset(dp, -1, sizeof(dp));
        long n, k;
        cin>>n>>k;
        cout<<solve(n, k)<<endl;
	}

	return 0;
}
