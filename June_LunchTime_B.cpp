#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
using namespace std;

bool sortbysec(const pair<long long, long long> &a,
              const pair<long long, long long> &b)
{
    return (a.first < b.first);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        string s, w;
        cin>>s;
        if(s[0] == '1'){
            cout<<"10";
            int i = 1;
            while(s[i] != '\0')
                cout<<s[i++];
        }
        else{
            w = '1' + s;
            cout<<w;
        }
        cout<<endl;
    }

    return 0;
}
