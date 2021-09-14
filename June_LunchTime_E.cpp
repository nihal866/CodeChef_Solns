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
        long long a, b;
        cin>>a>>b;
        long long i = 0, j = 0;
        bool p = false;
        while(i < b){
            i = pow(2, j++);
            if(i == b)
                p = true;
        }
        if(!p){
            if(a == 1)
                p = true;
        }
        if(p)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}
