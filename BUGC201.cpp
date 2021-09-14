#include<bits/stdc++.h>
using namespace std;
#define bruh main
int bruh(){
int n, d;
cin>>n;
vector<int> v;
for(int i=0;i<n;i++)
{
	cin>>d;
	v.push_back(d);
}
sort(v.begin(),v.end());
cout<<v[n-1]+v[n-2]<<endl;
return 0;
}
