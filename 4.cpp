#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t, n, cnt;
    cin>>t;
    while(t--){
        cin>>n;
        long long arr[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        cnt = n;
        for(int i = 0; i < n-1; i++){
            if(arr[i+1]>arr[i]){
                cnt--;
                arr[i+1] = arr[i];
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
