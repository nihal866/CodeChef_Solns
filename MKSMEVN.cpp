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
        bool even = false;
        long arr[n];
        long long sum = 0;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            if(arr[i] % 2 == 0)
                if((arr[i]/2) % 2 == 0)
                    even = true;
            sum += arr[i];
        }
        if(sum % 2 != 0){
            if(even)
                cout<<1<<endl;
            else
                cout<<-1<<endl;
        }
        else
            cout<<0<<endl;
    }

    return 0;
}
