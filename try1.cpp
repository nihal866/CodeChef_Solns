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
        int n;
        bool one = false;
        cin>>n;
        string s;
        cin>>s;
        int p[n];
        for(int i = 0; i < n; i++)
            cin>>p[i];
        int i = n-1;
        int cnt = 0;
        while(true){
            if(s[i] == '1'){
                while(true){
                    if(p[i] == '1'){
                        one = true;
                        break;
                    }
                    i = p[i] - 1;
                    cnt++;
                }
                if(!one)
                    break;
            }
            i++;
            cnt = 0;
        }
        cout<<cnt<<endl;
    }

    return 0;
}
