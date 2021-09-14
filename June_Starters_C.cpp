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
        string s;
        int val;
        cin>>n;
        std::map<string, int> mp;
        std::map<string,int>::iterator it;
        for(int i = 0; i < 3; i++){
            for(int i = 0; i < n; i++){
                cin>>s>>val;
                it = mp.find(s);
                if(it != mp.end())
                    it->second += val;
                else
                    mp.insert(make_pair(s, val));
            }
        }
        vector<int> v;
        v.reserve(100000);
        for(it = mp.begin(); it != mp.end(); it++)
            v.push_back(it->second);
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }

    return 0;
}
