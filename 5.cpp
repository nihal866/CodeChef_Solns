#include<bits/stdc++.h>
#include<string>
#include<algorithm>
using namespace std;

bool ispallindrome(string s){
	for(int i = 0; i <= s.size()/2 - 1; i++){
		if(s[i] != s[s.size() - 1 - i])
			return false;
	}
	return true;
}

int main(){
	string s;
	cin>>s;
	int cnt = s.size();
	for(int i = 0; i < s.size(); i++){
		for(int len = 3; len <= s.size(); len += 2){
			if(ispallindrome(s.substr(i, len))){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
