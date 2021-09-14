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
        int n;
        long val;
        cin>>n;
        vector<long> even;
        even.reserve(1000);
        vector<long> odd;
        odd.reserve(1000);
        for(int i = 0; i < n; i++){
            cin>>val;
            if(val%2 == 0)
                even.push_back(val);
            else
                odd.push_back(val);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        int i = 0;
        int s = min(even.size(), odd.size());
        while(i < s){
            cout<<even[i]<<" "<<odd[i]<<" ";
            i++;
        }
        while(i < even.size())
            cout<<even[i++]<<" ";
        while(i < odd.size())
            cout<<odd[i++]<<" ";
        cout<<endl;
        even.clear();
        odd.clear();
    }

    return 0;
}
