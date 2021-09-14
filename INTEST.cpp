#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    long n, k, num, cnt = 0;
    cin>>n>>k;
    for(long i = 0; i < n ; i++){
        cin>>num;
        if(num%k == 0)
            cnt++;
    }
    cout<<cnt;
    return 0;
}
