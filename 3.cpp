#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, sr, sc, er, ec;
    cin>>n;
    int a[2*n - 1][2*n - 1];
    sc = 0;
    er = 2*n - 2;
    sr = sc;
    ec = er;
    for(int i = n; i >= 1; i--){
        for(int j = sc; j <= ec; j++){
            a[i][j] = i;
        }
        sr++;
        for(int j = sr; j <= er; j++){
            a[i][j] = i;
        }
        ec--;
        for(int j = ec; j >= sc; j--){
            a[i][j] = i;
        }
        er--;
        for(int j = er; j >= sr; j--){
            a[i][j] = i;
        }
        sc++;
    }
    for(int i = 0; i < 2*n - 1; i++){
        for(int j = 0; j < 2*n - 1; j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
