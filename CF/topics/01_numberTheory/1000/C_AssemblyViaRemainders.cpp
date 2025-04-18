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
        vector<int> x(n-1);
        vector<int> ans;
        int cte = 1e6;
        ans.push_back(cte);
        for(int i=0;i<n-1;i++){
            cin >> x[i];
            ans.push_back(ans.back() + x[i]);
        }
        for(auto e : ans) cout << e << " "; cout << endl;
    }
    return 0;
}

