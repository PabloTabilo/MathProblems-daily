#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int l, r, k;
	cin >> l >> r >> k;
	int sz = r - l + 1;
	if(sz == 1){
	    if(l > 1){
		cout << "YES" << endl;
	    }else{
		cout << "NO" << endl;
	    }
	}else if(k == 0){
	    cout << "NO" << endl;
	}
	// sz > 1 && k >= 1
	else{
	    bool le = l % 2 == 0; // l even
	    bool re = r % 2 == 0; // r even
	    int num_odds;
	    if(!le && !re){
		num_odds = sz / 2 + 1;
	    }else if((le && !re) || (!le && re)){
		num_odds = sz / 2;
	    }else{
		num_odds = sz / 2;
	    }

	    if(num_odds <= k){
		cout << "YES" << endl;
	    }else{
		cout << "NO" << endl;
	    }

	}
    }
    return 0;
}

