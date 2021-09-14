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
        string s;
        cin>>s;
        int n = s.size();
        bool gud = true;
        if(s[0]!='<' || s[1]!='/')
            gud = false;
        if(n == 3)
            gud = false;
        if(gud){
            if(s[n-1] != '>')
                gud = false;
            if(gud){
                for(int i = 2; i < n-1; i++){
                    int m = (int)s[i];
                    if((m>=48 && m<= 57) || (m>=97 && m<=122))
                        gud = true;
                    else{
                        gud = false;
                        break;
                    }
                }
            }
        }
        if(gud)
            cout<<"Success"<<endl;
        else
            cout<<"Error"<<endl;
    }

    return 0;
}
