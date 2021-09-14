#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e+6;
int arr[N] = {0};

int main(){
    vector<int> v;
    int a, b, c, nu;
    cin>>a>>b>>c;
    v.reserve(a+b+c);
    for(int i = 0; i < a+b+c; i++){
        cin>>nu;
        arr[nu]++;
    }
    for(int i = 0; i < N; i++){
        if(arr[i] > 1)
            v.push_back(i);
    }
    cout<<v.size()<<endl;
    for(int i = 0; i < v.size(); i++)
        cout<<v[i]<<endl;

    return 0;
}
