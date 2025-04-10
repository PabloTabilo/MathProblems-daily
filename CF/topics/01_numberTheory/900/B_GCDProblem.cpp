#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a, b, c;
        if(n%2 == 0){
            c = 1;
            n--;
            a = n / 2;
            b = n - a;
        }else{
            c = 1;
            n--;
            a = n / 2;
            if(a%2 == 0){
                a--;
            }else{
                a -= 2;
            }
            b = n - a;
        }
        cout << a << " " << b << " " << c << endl; 
    }
    return 0;
}

