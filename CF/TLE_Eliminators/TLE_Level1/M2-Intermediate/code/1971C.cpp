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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int mx = max(a, b);
	int mn = min(a, b);

	int r1 = mx + 1;
	if(r1 == 13){
	    r1 = 1;
	}
	int r2 = mn - 1;
	if(r2 == 0){
	    r2 = 12;
	}
	int MOD = 13;
	set<int> sr, sl;
	//cout << "r1 = " << r1 << ", r2 = " << r2 << endl;
	sr.insert(r2);
	while(r1 != r2){
	    if (r1 != 0)
		sr.insert(r1);
	    r1++;
	    r1 = r1 % MOD;
	    if(r1 == 0)
		r1 = 1;
	}
	//cout << "sr: "; for(auto x : sr) cout << x << " "; cout << endl;
	int l1 = mx - 1;
	int l2 = mn + 1;
	if(l1 == 0){
	    l1 = 12;
	}
	if(l2 == 13){
	    l2 = 1;
	}
	//cout << "l1 = " << l1 << ", l2 = " << l2 << endl;
	sl.insert(l2);
	while(l1 != l2){
	    if(l1 != 0)
		sl.insert(l1);
	    l1--;
	    if(l1 == 0){
		l1 = 12;
	    }
	}
	//cout << "sl: "; for(auto x : sl) cout << x << " "; cout << endl;
	if(!sr.empty() && sr.count(c) > 0 && sr.count(d) > 0){
	    cout << "NO" << endl;
	}
	else if(!sl.empty() && sl.count(c) > 0 && sl.count(d) > 0){
	    cout << "NO" << endl;
	}else{
	    cout << "YES" << endl;
	}
    }
    return 0;
}

