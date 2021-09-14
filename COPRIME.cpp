#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;

bool coprime(int a, int b) {

    if ( __gcd(a, b) == 1)
        return true;
    else
        return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long l, r;
        cin>>l>>r;
        long i = l;
        for(long x = 2; x < 2 * pow(10, 9); x++){
            if(!coprime(x, i)){
                i = l;
                x++;
            }
            if(coprime(x, i)){
                if(i == r){
                    cout<<x-1<<endl;
                    break;
                }
                i++;
            }
        }
    }
    return 0;
}
