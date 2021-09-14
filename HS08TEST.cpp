#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;

int main(){
    int with;
    float bal;
    cin>>with>>bal;
    cout<<setprecision(2)<<fixed;
    if(with%5 == 0 && with<bal)
        cout<<bal - with - 0.50<<endl;
    else
        cout<<bal<<endl;
    return 0;
}
