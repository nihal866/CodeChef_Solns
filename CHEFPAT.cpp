#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;

void func(vector<int> v, int arr[], int n, int k){
    if(k > n)
        return;
    int ind = max_element(v.begin(), v.end()) - v.begin();
    v[ind] = INT_MIN;
    func(v, arr, n, k+1);
    arr[ind] = k;
}

int main(){
    int t, n, nu, ind;
    vector<int> v;
    v.reserve(100009);
    cin>>t;
    while(t--){
        cin>>n;
        int hr[n];
        for(int i = 0; i < n; i++){
            cin>>nu;
            v.push_back(nu);
        }
        func(v, hr, n, 1);
        for(int i = 0; i < n; i++){
            cout<<hr[i]<<" ";
        }
        v.clear();
        cout<<endl;
    }
    return 0;
}
