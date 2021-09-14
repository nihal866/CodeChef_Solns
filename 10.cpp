#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int isValid(string s) {
    int n = s.length();
    int cnt = 0;
    int arr[100];
    for(int i = 0; i < n; i++){
        if(s[i] == '.'){
            arr[cnt] = i
            cnt++;
        }
    }
    if(cnt != 3)
        return 0;
    for(int i = 0; i < n; i++){
        if(s[arr[ctm])
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<isValid(s)<<endl;
    }

    return 0;
}
