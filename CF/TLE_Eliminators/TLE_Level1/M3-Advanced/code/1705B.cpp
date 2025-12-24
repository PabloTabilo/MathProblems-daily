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
	vector<ll> a(n);
	int l = -1;
	for(int i=0;i<n;i++){
	    cin >> a[i];
	    if(a[i] != 0 && l == -1){
		l = i;
	    }
	}
	if(l == n-1 || l == -1){
	    cout << 0 << endl;
	    continue;
	}
	ll ans = 0;
	for(;l < n-1;l++){
	    ans += (a[l] == 0LL ? 1LL : a[l]);
	}
	//cout << "ans = ";
	cout << ans << endl;
    }

    return 0;
}

