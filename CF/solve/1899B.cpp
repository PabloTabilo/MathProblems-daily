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

vector<ll> getDivisors(ll x){
    vector<ll> p;
    for(ll i=1;i*i<=x;i++){
	if(x % i == 0){
	    p.push_back(i);
	    if(i*i != x){
		p.push_back(x / i);
	    }
	}
    }
    return p;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
	    cin >> a[i];
	}
	vector<ll> p = getDivisors(n);
	ll ans = 0;
	for(ll sz : p){
	    int r = 0;
	    ll mx = LLONG_MIN;
	    ll mn = LLONG_MAX;
	    //cout << "sz = " << sz << endl;
	    for(int l = 0; l < n; l+=sz){
		ll curr = 0;
		while(r < n && (r-l+1)<=sz){
		    curr += a[r];
		    r++;
		}
		//cout << "l, r = " << l << ", " << r << " -> curr = " << curr << endl;
		mx = max(mx, curr);
		mn = min(mn, curr);
	    }
	    //cout << "mx = " << mx << ", mn = " << mn << endl;
	    ll d = abs(mx - mn);
	    ans = max(ans, d);
	    //cout << "ans = " << ans << endl;
	}
	//cout << "final ans = ";
	cout << ans;
	//cout << endl;
	cout << '\n';
    }

    return 0;
}

