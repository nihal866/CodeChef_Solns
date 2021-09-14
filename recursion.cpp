#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

vector<string> v;

void solve(int open, int close, string op){
    if(close == 0 && open == 0){
        v.push_back(op);
        return;
    }
    if(open != 0){
        string op1 = op;
        op1 += "(";
        solve(open-1, close, op1);
    }
    if(close > open){
        string op2 = op;
        op2 += ")";
        solve(open, close-1, op2);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, close, open;
	cin>>n;
	close = n;
	open = n;
	string op = "";
	solve(open, close, op);
	for(int i = 0; i < v.size(); i++)
        cout<<v[i]<<endl;

    return 0;
}


void inser(vector<int> &v, int temp){
    if(v.size() == 0 || v[v.size() - 1] <= temp){
        v.push_back(temp);
        return;
    }
    int val = v[v.size()-1];
    v.pop_back();
    inser(v, temp);
    v.push_back(val);
    return;
}

void sor(vector<int> &v){
    if(v.size() == 0)
        return;
    int temp = v[v.size() - 1];
    v.pop_back();
    sor(v);
    inser(v, temp);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> v;
	v.push(10);
	v.push(15);
	v.push(1);
	v.push(20);
	v.push(14);
	sor(v);
	for(int i = 0; i < v.size(); i++)
        cout<<v[i]<<endl;

    return 0;
}

void solve(stack<int> &s, int k){
    if(k == 1){
        s.pop();
        return;
    }
    int val = s[top];
    s.pop();
    solve(s, k-1);
    s.push();
    return;
}

stack<int> mid_delete(stack<int> &s){
    if(s.size() == 0)
        return s;
    int k = s.size()/2 + 1;
    solve(s, k);
    return s;
}

void sol(stack<int> &s){
    if(s.size() == 1)
        return;
    int val = s[s->top];
    s.pop();
    sol(s);
    inse(s, val);
    return;
}

void inse(stack<int> &s, int val){
    if(s.size() == 0){
        s.push(val);
        return;
    }
    int temp = s[s->top];
    s.pop();
    inse(s, val);
    s.push(temp);
    return;
}

int solve(int n, int k){
    if(n == 1 && k == 1)
        return 0;
    int mid = pow(2, n-1) / 2;
    if(k <= mid)
        return solve(n-1, k);
    else
        return !solve(n-1, k-mid);
}

void solveb(int s, int d, int h, int n){
    if(n == 1){
        s->d;
        return;
    }
    solveb(s, h, d, n-1);
    solveb(h, d, s, n-1);
    return;
}

void solves(string ip, string op){
    if(ip.size() == 0){
        cout<<op<<endl;
        return;
    }

    string op1 = op;
    string op2 = op.push_back(ip[0]);

    ip.erase(ip.begin() + 0);
    solves(ip, op1);
    solves(ip, op2);
    return;
}


void solve(int o, int z, string op, int n){
    if(n == 0){
        cout<<op<<endl;
        return;
    }
    if(o > z){
        string op1 = op + "0";
        solve(o, z+1, op1, n-1);
        string op2 = op + "1";
        solve(o+1, z, op2, n-1);
    }
    if(o == z){
        string op3 = op + "1";
        solve(o+1, z, op3, n-1);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, o = 0, z = 0;
	cin>>n;
	string op = "";
	solve(o, z, op, n);

    return 0;
}


vector<int> v;

void solve(int index, int k){
    if(v.size() == 1){
        cout<<v[0]<<endl;
        return;
    }
    index = (index + k) % v.size();
    v.erase(v.begin() + index);
    solve(index, k);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin>>n>>k;
	k--;
	for(int i = 0; i < n; i++)
        v.push_back(i+1);
    int index = 0;
    solve(index, k);

    return 0;
}
