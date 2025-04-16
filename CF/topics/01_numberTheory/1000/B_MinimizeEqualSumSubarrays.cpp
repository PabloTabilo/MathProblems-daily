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
        vector<int> p(n);
        vector<int> q(n);
        for(int i=0;i<n;i++){
            cin >> p[i];
            q[i] = p[i] - 1;
            if(q[i] == 0){
                q[i] = n;
            }
        }
        for(auto x : q) cout << x << " ";
        cout << endl;
    }
    return 0;
}

