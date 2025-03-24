#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	ll n;
	cin >> n;
	ll n_isolate = n;
	set<ll> pf;
	for(ll i=2;i*i<=n;i++){
	    while(n % i == 0){
		pf.insert(i);
		n /= i;
	    }
	}
	if(n >= 1){
	    pf.insert(n);
	}
	//cout << "pf: ";for(ll x : pf){cout << x << " ";}cout << endl;
	//cout << "valid_points: ";for(ll x : valid_points){cout << x << " ";}cout << endl;
	// search BF
	ll ans = 1;
	for(ll p : pf){
	    ll l = p;
	    //cout << "valid_points[i] = " << l << endl;
	    while((l-1) >= 1 && (n_isolate % (l-1)) == 0){
		l--;
	    }
	    //cout << "l = " << l << endl;
	    ll r = p;
	    while((n_isolate % (r+1)) == 0){
		r++;
	    }
	    //cout << "r = " << r << endl;
	    ans = max(ans, r - l + 1);
	    //cout << "-------------------------" << endl;
	}
	//cout << "ans = ";
	cout << ans << endl;
	// 4204474560
	// 2 2 2 2 2 2 3 3 3 5 11 13 41 83
	// 2, 4, 8, 16, 32, 64, 3, 9, 27, 5, 11, 13, 41, 83  
	// valid_points:
	// 2, 3, 4, 5, 8, 9, 11, 13, 16, 27, 32, 41, 64, 83
	// search l, r for each point
	//
	// 2,3,4,5,6,
	// 8,9,10,11,12,13
	// 15, 16
	// 18,
	// 20,
	//
    }

    return 0;
}

