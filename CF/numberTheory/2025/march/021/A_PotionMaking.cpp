#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int k;
	cin >> k;
	int ans = 100;
	while(k % 2 == 0 && ans % 2 == 0){
	    k /= 2;
	    ans /= 2;
	}
	while(k % 5 == 0 && ans % 5 == 0){
	    k /= 5;
	    ans /= 5;
	}
	cout << ans << endl;
    }

    return 0;
}

