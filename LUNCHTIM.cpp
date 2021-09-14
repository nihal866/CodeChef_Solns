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

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n], b[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            b[i] = 0;
        }
        int j;
        for(int i = 0; i < n-1; i++){
            j = i+1;
            while(arr[j] <= arr[i]){
                if(arr[j] == arr[i]){
                    b[i]++;
                    b[j]++;
                }
                j++;
            }
        }
        for(int i = 0; i < n; i++){
            cout<<b[i]<<" ";
        }
    }

    return 0;
}
