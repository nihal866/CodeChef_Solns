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

    int t;
    cin>>t;
    while(t--){
        int n, cnt = 1, index;
        cin>>n;
        int arr[n];
        int num[n] = {0};
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        for(int i = 0; i < n; i++){
            num[arr[i] - 1]++;
            bool gud = true;
            for(int i = 0; i < 7; i++){
                if(num[i] == 0)
                    gud = false;
            }
            if(gud){
                index = i+1;
                break;
            }
        }
        cout<<index<<endl;
    }

    return 0;
}
