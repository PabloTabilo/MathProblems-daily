#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int l, r;
	cin >> l >> r;
	// odd, even, odd
	int nodd = 0;
	for(int x = l; x <= r; x++){
	    if(x % 2 == 1){
		nodd++;
	    }
	}
	int ans = nodd / 2;
	//cout << "ans = ";
	cout << ans << endl;
    }
    return 0;
}

