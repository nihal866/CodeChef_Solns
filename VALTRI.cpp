#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin>>n;
    if((n%6 == 0) || (n%5 == 0))
        cout<<"YES"<<endl;
    else
        cout<<"NO";

    return 0;
}
