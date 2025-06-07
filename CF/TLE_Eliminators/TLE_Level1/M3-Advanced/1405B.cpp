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
	for(int i=0;i<n;i++){
	    cin >> a[i];
	}
	ll cand = LLONG_MAX;
	int p1 = 0;
	int p2 = -1;
	for(;p1<n && p2 < n;){
	    while(p1 < n && cand == LLONG_MAX){
		if(a[p1] > 0){
		    cand = a[p1];
		    break;
		}
		p1++;
	    }
	    if(p2 <= p1){
		p2 = p1 + 1;
	    }
	    while(p2 < n){
		if(a[p2] < 0){
		    int v = min(cand, -a[p2]);
		    if(v >= cand){
			cand = LLONG_MAX;
			a[p1] = 0;
			a[p2] += v;
			break;
		    }else{
			cand -= v;
			a[p2] = 0;
			a[p1] = cand;
		    }
		}
		p2++;
	    }
	}
	ll ans = 0;
	//cout << "POST a: ";
	for(auto x : a){
	    if(x > 0){
		ans += x;
	    }
	    //cout << x << " ";
	}
	//cout << endl;
	//cout << "ans : ";
	cout << ans << endl;
    }

    return 0;
}

