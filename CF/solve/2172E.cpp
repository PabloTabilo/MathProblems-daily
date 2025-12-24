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
	string n;
	int j, k;
	cin >> n >> j >> k;
	set<string> perms;
	int sz = n.size();
	function<void(string, int )> f = [&](string pe, int mask){
	    int pe_sz = pe.size();
	    if(pe_sz == sz){
		perms.insert(pe);
		return;
	    }
	    for(int i=0;i<sz;i++){
		if( (mask&(1<<i)) == 0){
		    pe += n[i];
		    f(pe, mask|(1<<i));
		    pe.pop_back();
		}
	    }
	};
	string init = "";
	f(init, 0);
	vector<string> ans(perms.begin(), perms.end());
	string s1 = ans[j-1];
	string s2 = ans[k-1];
	/*
	cout << "ans: ";
	for(auto x : ans){
	    cout << x << " ";
	}
	cout << endl;
	*/
	//cout << "s1 = " << s1 << " vs " << s2 << endl;
	int x = 0;
	for(int i=0;i<sz;i++){
	    if(s1[i] == s2[i]){
		x++;
	    }
	}
	int y = sz - x;
	cout << x << "A" << y << "B";
	//cout << endl;
	cout << '\n';
    }

    return 0;
}

