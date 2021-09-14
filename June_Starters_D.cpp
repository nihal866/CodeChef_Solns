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
        long long l, h, cnt = 0;
        cin>>l>>h;
        string s;
        bool so = false;
        vector<int> v;
        v.reserve(100000);
        cin>>s;
        for(int i = 0; i < l; i++){
            if(s[i]=='0')
                cnt++;
            else{
                v.push_back(cnt);
                cnt = 0;
            }
        }
        v.push_back(cnt);
        for(int i = 0; i < v.size(); i++){
            if(v[i] > 0){
                if(v[i] >= h){
                    so = true;
                    break;
                }
                else{
                    h = 2*(h - v[i]);
                }
            }
        }
        if(so)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
