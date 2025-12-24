#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int mx = -1;
    int v;
    unordered_map<int,int> cnt;
    for(int i=0;i<n;i++){
	cin >> v;
	cnt[v]++;
	mx = max(mx, v);
    }

    cnt[mx]--;
    ll ans = 0;
    for(auto [k, val] : cnt){
	if(val == 0){
	    continue;
	}
	ll diff = (ll)mx - (ll)k;
	ans += (diff * (ll)val);
    }
    cout << ans << endl;
    return 0;
}

