#include  <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll cb = c * b;
	// a/b = c/d * x
	ll ad = a * d;
	//cout << "ans = ";
	if(ad == cb){
	    cout << 0 << endl;
	    continue;
	}
	if(ad == 0 || cb == 0){
	    cout << 1 << endl;
	    continue;
	}
	ll mx = max(cb, ad);
	ll mn = min(cb, ad);
	if(mx % mn != 0){
	    cout << 2 << endl;
	}else{
	    cout << 1 << endl;
	}
    }

    return 0;
}

