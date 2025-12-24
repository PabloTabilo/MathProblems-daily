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
	ll n, K;
	cin >> n >> K;
	vector<ll> a(n), b(n);
	for(int i=0;i<n;i++){
	    cin >> a[i];
	}
	for(int i=0;i<n;i++){
	    cin >> b[i];
	}
	function<ll(ll, int, bool, ll)> f = [&](ll s, int i, bool firstTime, ll k){
	    if(i >= n){
		return -1LL;
	    }
	    if(k <= 0){
		return s;
	    }
	    if(firstTime){
		s += a[i];
	    }else{
		s += b[i];
	    }
	    ll op1 = f(s, i, false, k-1);
	    ll op2 = f(s, i+1, true, k-1);
	    return max(op1, op2);
	};
	//ll ans = f(0, 0, true, K);
	ll ans = 0;
	ll acc = 0;
	ll mx = -1;
	for(int i=0;i<K && i<n;i++){
	    acc += (ll)a[i];
	    mx = max(mx, (ll)b[i]);
	    ll r = K - (i+1);
	    ans = max(ans, acc + (r*mx));
	}
	//cout << "ans = ";
	cout << ans;
	//cout << endl;
	cout << '\n';
    }
    return 0;
}

