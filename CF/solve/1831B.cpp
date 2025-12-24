#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace chrono;

/* -- Red black tree for build a set that can get kth position -- */
/* -- not accept duplicates, its possible to implement? -- */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;


using ll = long long;
using pii = pair<int,int>;

void printDouble(double d){
    // fix precision, the fixed is for evit rounding 
    // rounding can be different for each compiler
    cout << fixed << setprecision(11) << d << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int n;
	cin >> n;
	unordered_map<int, int> a;
	int prev = -1;
	int cnt = 0;
	for(int i=0;i<n;i++){
	    int ai;
	    cin >> ai;
	    if(prev == -1){
		prev = ai;
		cnt = 1;
	    }else if(prev == ai){
		cnt++;
	    }else{
		if(a.find(prev) == a.end()){
		    a[prev] = 0;
		}
		a[prev] = max(a[prev], cnt);
		cnt = 1;
		prev = ai;
	    }
	}
	if(a.find(prev) == a.end()){
	    a[prev] = 0;
	}
	a[prev] = max(a[prev], cnt);
	prev = -1;
	cnt = 0;
	unordered_map<int, int> b;
	for(int i=0;i<n;i++){
	    int bi;
	    cin >> bi;
	    if(prev == -1){
		prev = bi;
		cnt = 1;
	    }else if(prev == bi){
		cnt++;
	    }else{
		if(b.find(prev) == b.end()){
		    b[prev] = 0;
		}
		b[prev] = max(b[prev], cnt);
		cnt = 1;
		prev = bi;
	    }
	}
	if(b.find(prev) == b.end()){
	    b[prev] = 0;
	}
	b[prev] = max(b[prev], cnt);
	/*
	cout << "a: ";
	for(auto p : a){
	    cout << "<"<<p.first<<","<<p.second<<"> ";
	}
	cout << endl;
	cout << "b: ";
	for(auto p : b){
	    cout << "<"<<p.first<<","<<p.second<<"> ";
	}
	cout << endl;
	*/
	ll ans = 0;
	for(auto [k1, v1] : a){
	    ll local = (ll)v1;
	    if(b.find(k1) != b.end()){
		local += (ll)b[k1];
	    }
	    ans = max(ans, local);
	}
	for(auto [k1, v1] : b){
	    ll local = (ll)v1;
	    if(a.find(k1) != a.end()){
		local += (ll)a[k1];
	    }
	    ans = max(ans, local);
	}
	//cout << "ans = ";
	cout << ans;
	//cout << endl;
	cout << '\n';
    }
    return 0;
}

