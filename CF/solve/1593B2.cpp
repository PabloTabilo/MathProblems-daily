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
	ll n;
	cin >> n;
	string t = to_string(n);
	int sz = t.size();
	// finish
	auto getOpe = [&](char c1, char c2){
	    int op = INT_MAX;
	    int r = sz-1;
	    while(r>=0 && t[r] != c1){
		r--;
	    }
	    int l = r-1;
	    while(l>=0 && t[l] != c2){
		l--;
	    }

	    if(l != -1 && r != -1){
		int rightOperations = sz - r - 1;
		int midOperations = r - l - 1;
		op = min(op, rightOperations + midOperations);
	    }
	    return op;
	};
	// 00
	int op00 = getOpe('0','0');
	// 25
	int op25 = getOpe('5','2');
	// 50
	int op50 = getOpe('0','5');
	// 75
	int op75 = getOpe('5','7');
	int ans = min(op00, min(op25, min(op50, op75)));
	//cout << "ans = ";
	cout << ans;
	//cout << endl;
	cout << '\n';
    }

    return 0;
}

