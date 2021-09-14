#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int groups = 0;
        bool one = false;
        if(s[0] == '1')
            one = true;
        for(int i = 0; i < s.length(); i++){
            if(one){
                if(s[i+1] == '0' || i == s.length() - 1){
                    groups++;
                    one = false;
                }
            }
            else{
                if(s[i+1] == '1')
                    one = true;
            }
        }
        cout<<groups<<endl;
    }
    return 0;
}
