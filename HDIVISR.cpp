#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n;
    for(int i = 1; i <= n; i++){
        if(n % i == 0)
            m = i;
        if(i > 10)
            break;
    }
    cout<<m<<endl;
    return 0;
}
