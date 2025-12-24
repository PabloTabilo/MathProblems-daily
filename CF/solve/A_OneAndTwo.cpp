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
        int n;
        cin >> n;
        vector<ll>a(n);
        ll tot2s = 0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[i] == 2){
                tot2s++;
            }
        }
        if(tot2s == 0){
            cout << 1 << endl;
            continue;
        }
        if(tot2s % 2 != 0){
            cout << -1 << endl;
            continue;
        }
        int k = -1;
        int c2s = 0;
        for(int i=0;i<n;i++){
            if(a[i] == 2){
                c2s++;
            }
            if(c2s == (tot2s - c2s)){
                k = i;
                break;
            }
        }
        cout << k+1 << endl;
    }

    return 0;
}

