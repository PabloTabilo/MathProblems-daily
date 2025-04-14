#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        int tot = 0;
        while(a > 0 && b > 0){
            int mx = max(a, b);
            int mn = min(a, b);
            int ope = mx / mn;
            tot += ope;
            mx = mx - (mn*ope);
            a = mx;
            b = mn; 
        }
        cout << tot << endl;
    }

    return 0;
}

