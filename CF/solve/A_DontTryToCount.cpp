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
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x;
        cin >> s;
        bool isPossible = true;
        int ans = -1;
        for(int start=0;start<n;start++){
            if(x[start] == s[0]){
                int i = start;
                int loop = 0;
                isPossible = true;
                for(int j=0;j<m;j++){
                    if(x[i] == s[j]){
                        i++;
                        if(i == n){
                            if(j < m - 1){
                                loop++;
                            }
                            i %= n;
                        }
                    }else{
                        isPossible = false;
                    }
                }
                if(isPossible){
                    if(loop == 0){
                        ans = 0;
                    }else{
                        ans = floor(log2(loop)) + 1;
                    }
                    break;
                }
            } 
        }
        cout << ans << endl;

    }

    return 0;
}

