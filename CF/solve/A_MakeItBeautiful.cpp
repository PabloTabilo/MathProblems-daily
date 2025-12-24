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
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> best;
        for(int i = 0; i<n;i++){
            int p1 = i;
            int p2 = n - 1 - i;
            if(p1 >= p2){
                if(p1 == p2){
                    best.push_back(a[p1]);
                }
                break;
            }
            // mx
            best.push_back(a[p2]);
            // mn
            best.push_back(a[p1]);
        }
        bool isPossible = true;
        int prefixSum = 0;
        for(auto x : best){
            if(prefixSum == x){
                isPossible = false;
                break;
            }
            prefixSum += x;
        }
        if(isPossible){
            cout << "YES" << endl;
            for(auto x : best) cout << x << " "; cout << endl;
        }else{
            cout << "NO" << endl;
        }

    }
    return 0;
}

