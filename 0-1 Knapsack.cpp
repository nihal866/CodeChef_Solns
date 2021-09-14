#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

//Recursive way
int knapsack(int wt[], int val[], int cap, int n){
    if(n == 0 || cap == 0)
        return 0;
    if(wt[n-1] <= cap)
        return max(val[n-1] + knapsack(wt, val, cap - wt[n-1], n-1), knapsack(wt, val, cap, n-1));
    else
        return knapsack(wt, val, cap, n-1);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 4, wt[4] = {1, 3, 4, 5};
	int val[4] = {1, 4, 5, 7};
	int cap = 8;

	//Top-down approach
	int dp[n+1][cap+1] = {-1};
	for(int i = 0; i <= n; i++){
        for(int j = 0; j <= cap; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
	}
	for(int i = 1; i <= n; i++){
        for(int j = 1; j <= cap; j++){
            if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
	}
	cout<<dp[n][cap]<<endl;

    return 0;
}
