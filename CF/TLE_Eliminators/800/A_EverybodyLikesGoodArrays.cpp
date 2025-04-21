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
        int ope = 0;
        int even = 0;
        int odd = 0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[i] % 2 != 0){
                if(even >= 1){
                    ope += even-1;
                }
                odd++;
                even = 0;
            }else{
                if(odd >= 1){
                    ope += odd-1;
                }
                even++;
                odd = 0;
            }
        }
        if(even >= 1){
            ope += even - 1;
        }
        if(odd >= 1){
            ope += odd - 1;
        }
        cout << ope << endl;
    }

    return 0;
}

