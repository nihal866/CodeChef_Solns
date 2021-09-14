#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    vector<long> v;
    v.reserve(1000001);
    vector<int> c;
    c.reserve(4001);
    int m, i;
    long n, nu;
    cin>>n;
    while(n--){
        cin>>nu;
        v.push_back(nu);
    }
    cin>>m;
    while(m--){
        cin>>i;
        c.push_back(v[i-1]);
        v.erase(v.begin() + i - 1);
    }
    for(int j = 0; j < c.size(); j++)
        cout<<c[j]<<endl;
    return 0;
}
