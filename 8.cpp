#include<bits/stdc++.h>
using namespace std;

int main(){
    long t, n, i, cnt1, cnt2;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        cnt1 = 0;
        cnt2 = 0;
        for(i = 0; i < 2*n; i += 2){
            cnt1 += (s[i] - '0');
            cnt2 += (s[i+1] - '0');
            if((2*n) - i < cnt1 + cnt2)
                break;
        }
        cout<<i<<endl;
    }
    return 0;
}
