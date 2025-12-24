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
	string s;
	cin >> s;
	unordered_map<char, int> f;
	for(auto c : s){
	    f[c]++;
	}
	if(f.size() == 1){
	    cout << s << '\n';
	    continue;
	}
	char cmx;
	int mx = 0;
	for(auto [k, v] : f){
	    if(v > mx){
		mx = v;
		cmx = k;
	    }
	}
	char cmn;
	int mn = INT_MAX;
	for(auto [k, v] : f){
	    if(cmx != k && v < mn){
		mn = v;
		cmn = k;
	    }
	}
	//cout << "cmx, mx = " << cmx << ", " << mx << endl; 
	//cout << "cmn, mn = " << cmn << ", " << mn << endl; 
	string t = "";
	bool oneTime = true;
	for(int i=0;i<n;i++){
	    if(s[i] == cmn && oneTime){
		t += cmx;
		oneTime = false;
		continue;
	    }
	    t += s[i];
	}
	cout << t << '\n';
    }

    return 0;
}

