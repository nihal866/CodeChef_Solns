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
        int w1, w2, x1, x2, m;
        cin>>w1>>w2>>x1>>x2>>m;
        int diff = w2 - w1;
        int mi = x1 * m;
        int ma = x2 * m;
        if(diff >= mi && diff <= ma)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}
