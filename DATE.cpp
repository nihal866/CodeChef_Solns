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
        long a, y, x;
        cin>>a>>y>>x;
        if(y>a)
            cout<<a*x+1<<endl;
        else
            cout<<y*x<<endl;
    }

    return 0;
}
