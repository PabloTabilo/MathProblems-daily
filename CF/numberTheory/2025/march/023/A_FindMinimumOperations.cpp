#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	ll n, k;
	cin >> n >> k;
	ll ope = 0;
	if(k == 1){
	    cout << n << endl;
	    continue;
	}
	while(n > 0){
	    ll v = 1;
	    while(n > v){
		v *= k;
	    }
	    if(v > n){
		v /= k;
	    }
	    if(v == 1){
		ope += n;
		n = 0;
	    }else{
		n -= v;
		ope++;
	    }
	}
	cout << ope << endl;
    }

    return 0;
}

