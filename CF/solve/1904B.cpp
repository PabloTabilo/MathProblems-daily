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
	vector<ll> a(n), sa(n);
	unordered_map<ll, ll> ans;
	for(int i=0;i<n;i++){
	    cin >> a[i];
	    sa[i] = a[i];
	    ans[a[i]] = 0;
	}
	vector<ll> prefix(n, 0);
	sort(sa.begin(), sa.end());
	prefix[0] = sa[0];
	for(int i=1;i<n;i++){
	    prefix[i] = sa[i] + prefix[i-1];
	}
	/*
	cout << "sorted a: ";
	for(auto x : sa){
	    cout << x << " ";
	}
	cout << endl;

	cout << "prefix: ";
	for(auto x : prefix){
	    cout << x << " ";
	}
	cout << endl;
	*/
	for(int i=n-1;i>=0;i--){
	    ll p = prefix[i];
	    auto it = upper_bound(sa.begin(), sa.end(), p);
	    it--;
	    int idx = it - sa.begin();
	    //cout << "p = " << p << " and sa["<<i<<"] = "<<sa[i]<<", idx = " << idx << endl;
	    if(idx > i){
		ans[sa[i]] = ans[sa[idx]];
	    }else{
		ans[sa[i]] = i;
	    }
	    /*
	    cout << "ans: "<<endl;
	    for(auto [k, v] : ans){
		cout << k << " -> " << v << endl;
	    }
	    cout << endl;
	    */
	}
	//cout << "ans: ";
	for(auto x : a){
	    cout << ans[x] << " ";
	}
	cout << '\n';
	//cout << endl;
    }

    return 0;
}

