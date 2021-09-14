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

    int n, q;
    cin>>n>>q;
    long long arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    while(q--){
        long long l, r, x, y, qu;
        cin>>qu;
        if(qu == 1){
            cin>>l>>r>>x;
            long long m = x - l + 1;
            for(long long i = l-1; i < r; i++)
                arr[i] += (m+i)*(m+i);
        }
        else{
            cin>>y;
            cout<<arr[y-1]<<endl;
        }
    }

    return 0;
}
