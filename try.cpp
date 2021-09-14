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
        int n, m;
        cin>>n>>m;
        int arr[n], b[m];
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        for(int i = 0; i < m; i++)
            cin>>b[i];
        int ind, time = INT_MAX;
        bool found = false;
        for(int j = 0; j < m; j++){
            if(arr[b[j]-1] != 0)
                time = 0;
            else{
                for(int i = (b[j]-2); i >= 0; i--){
                    if(arr[i] == 1){
                        found = true;
                        ind = i+1;
                        break;
                    }
                    if(arr[i] == 2)
                        break;
                }
                if(found)
                    time = abs(b[j] - ind);
                for(int i = (b[j]); i < n; i++){
                    if(arr[i] == 2){
                        found = true;
                        ind = i+1;
                        break;
                    }
                    if(arr[i] == 1)
                        break;
                }
                if(found)
                    time = min(time, abs(b[j] - ind));
                else
                    time = -1;
            }
            cout<<time<<" ";
        }
        cout<<endl;
	}

	return 0;
}
