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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int>cnt(26, 0);
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']++;
        }
        while(k > 0){
            for(int i=0;i<26;i++){
                if(cnt[i] > 0 && (cnt[i] % 2 == 1)){
                    cnt[i]--;
                    k--;
                }
                if(k == 0){
                    break;
                }
            } 
            if(k > 0){
                for(int i=0;i<26;i++){
                    if(cnt[i] > 0){
                        cnt[i]--;
                        k--;
                        break;
                    }
                }
            }
        }
        int cntOdd = 0;
        for(int i=0;i<26;i++){
            if((cnt[i] % 2) == 1){
                cntOdd++;
            }
        }
        if(cntOdd > 1){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }

    return 0;
}

