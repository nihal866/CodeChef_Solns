#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n, h, x;
    cin>>n>>h>>x;
    int diff = h - x;
    int arr[n];
    string found = "NO";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(arr[i] == diff)
            found = "YES";
    }
    cout<<found<<endl;
    return 0;
}
