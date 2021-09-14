#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, d0, d1, sum, num;
    long long k;
    cin>>t;
    while(t--){
        cin>>k>>d0>>d1;
        sum = d0 + d1;
        for(long long i = 0; i < k-2; i++){
            num = sum % 10;
            sum = (sum + num) % 30;
        }
        if(sum%3 == 0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
