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
	int n;
	cin >> n;
	vector<int>a(n);
	for(int i=0;i<n;i++){
	    cin >> a[i];
	}
	vector<int> pm(n, 0);
	for(int i=0;i<n;i++){
	    pm[i] = max(pm[i], a[i]);
	    if((i-1)>=0){
		pm[i] = max(pm[i], pm[i-1]);
	    }
	}
	for(int i=1;i<n;i+=2){
	    a[i] = pm[i];
	}
	int ans = 0;
	for(int i=0;i<n;i+=2){
	    int mn = INT_MAX;
	    int nxt = INT_MAX;
	    int prev = INT_MAX;
	    if((i-1)>=0){
		prev = a[i-1];
		mn = min(mn, prev);
	    }
	    if((i+1)<n){
		nxt = a[i+1];
		mn = min(mn, nxt);
	    }
	    //cout << "a["<<i<<"] = " << a[i] << ", mn = " << mn << '\n';
	    if(mn > a[i]) continue;
	    ans += abs(a[i] - mn) + 1;
	}
	/*
	cout << "new a: ";
	for(int x : a){
	    cout << x << " ";
	}
	cout << '\n';
	*/
	cout << ans << '\n';
    }
    return 0;
}

