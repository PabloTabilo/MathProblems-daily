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
	vector<int> a(n);
	set<pair<int, int>> s;
	for(int i=0;i<n;i++){
	    cin >> a[i];
	    s.insert({a[i], i});
	}
	vector<int> pos(n);
	for(int i = 1; i <= n && s.size() > 0; i++){
	    auto it = prev(s.end());
	    auto [v, idx] = *it;
	    //cout << "last1 >> v, idx = " << v << ", " << idx << endl;
	    pos[idx] = i;
	    s.erase(it);
	    if(s.size() <= 0){
		break;
	    }
	    it = prev(s.end());
	    v = (it->first);
	    idx = (it->second);
	    //cout << "last2 >> v, idx = " << v << ", " << idx << endl;
	    pos[idx] = -i;
	    s.erase(it);
	}
	ll ans = 0;
	for(int i=0;i<n;i++){
	    ans += 2LL*(ll)a[i]*abs(0LL - (ll)pos[i]);
	}
	//cout << "ans: ";
	cout << ans << endl;
	//cout << "pos: ";
	cout << 0 << " ";
	for(auto x : pos){
	    cout << x << " ";
	}
	cout << endl;
    }

    return 0;
}

