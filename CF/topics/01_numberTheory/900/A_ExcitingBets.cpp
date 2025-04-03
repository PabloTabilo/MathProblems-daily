#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	ll a, b;
	cin >> a >> b;
	if(a == b){
	    cout << 0 << " " << 0 << endl;
	    continue;
	}
	ll mx = max(a, b);
	ll mn = min(a, b);
	ll d = mx - mn;
	// 6, 8 -> 2*3 , 2*2*2 -> gcd = 2*2*2*3 = 24 -> +16 -> 22, 24 = 6
	// 21, 24 -> 7*3, 8*3 -> 3, 
	// 2 vs 11 -> 9, 18 -> 9, 18 = 9
	// 2 vs 10 -> 8, 16 -> 8,16 = 8
	cout << d << " " << min(a % d, d - (a % d) ) << endl;
    }

    return 0;
}

