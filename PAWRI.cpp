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
        int arr[100000];
        int k = 0;
        for(int i = 0 ; i < s.length(); i++){
            if(s[i] == 'p'){
                arr[k] = i;
                k++;
            }
        }
        int n = k;
        for(int j = 0; j < n; j++){
            if(s[arr[j]] == 'p' && s[arr[j]+1] == 'a' && s[arr[j]+2] == 'r' && s[arr[j]+3] == 't' && s[arr[j]+4] == 'y'){
                s[arr[j]+2] = 'w';
                s[arr[j]+3] = 'r';
                s[arr[j]+4] = 'i';
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
