#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

void printDouble(double d){
    // fix precision, the fixed is for evit rounding 
    // rounding can be different for each compiler
    cout << fixed << setprecision(11) << d << '\n';
}
const int MAX = 2e5;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    vector<ll> f(MAX+1,0);
    vector<ll> pref(MAX+1,0);

    for(int i=1;i<=MAX;i++){
	int curr = i;
	while(curr > 0){
	    curr /= 3;
	    f[i]++;
	}
	pref[i] = f[i] + pref[i-1];
    }

    int t;
    cin >> t;
    while(t--){
	int l, r;
	cin >> l >> r;
	// find lower value that on last step do something like 2 -> 0 or 1 -> 0
	// and evit 3 -> 1 -> 0
	// 3*x where x is lowers values after the lowest even
	ll ope = 2*f[l] + (pref[r] - pref[l]);
	cout << ope << '\n';
    }

    return 0;
}

