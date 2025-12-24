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

#ifdef debugcoding
#define debug(x) _print(x); cerr<<endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair<T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v){_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v){_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v){_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (T i : v){_print(i); cerr << " ";} cerr << "]";}

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
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	set<ll> uniques;
	ll mx = -1;
	for(int i=0;i<n;i++){
	    cin >> a[i];
	    uniques.insert(a[i]);
	    mx = max(mx, a[i]);
	}
	sort(a.begin(), a.end());
	vector<ll> prefix(n, 0);
	prefix[0] = a[0];
	for(int i=1;i<n;i++){
	    prefix[i] = a[i] + prefix[i-1];
	}
	/*
	cout << "a: ";
	for(auto x : a){
	    cout << x << " ";
	}
	cout << endl;
	
	cout << "prefix: ";
	for(auto p : prefix){
	    cout << p << " ";
	}
	cout << endl;
	*/

	ll ans = -1;
	ll best = -1;
	ll l = 1;
	ll r = mx;
	while(l <= r){
	    ll h = l + (r-l)/2;
	    auto it = lower_bound(a.begin(), a.end(), h);
	    int idx = it - a.begin();
	    //cout << "h = " << h << ", idx = " << idx << endl;
	    if(a[idx] >= h){
		idx--;
		//cout << "adjust idx = " << idx << endl;
	    }
	    ll prev = 0;
	    ll fill = 0;
	    ll diff = 0;
	    if(idx >= 0){
		prev = prefix[idx];
		fill = h*((ll)idx+1LL);
		diff = fill - prev;
	    }
	    //cout << "prev = " << prev << ", fill = " << fill << ", diff = " << diff << endl;
	    if(x >= diff){
		ans = h;
		best = diff;
		l = h + 1;
	    }else{
		r = h - 1;
	    }
	}
	
	
	if(ans == mx){
	    //cout << "best = " << best << ", x = " << x << endl;
	    x -= best;
	    ll times = x / n;
	    ans += times;
	    //cout << "ans is equal to mx"<<endl;
	    //cout << "x = " << x << endl;
	    //cout << "times = " << times << endl;
	    //cout << "new ans= " << ans << endl;
	}
	//cout << "FINAL ans = ";
	cout << ans;
	//cout << endl;
	cout << '\n';
    }

    return 0;
}

