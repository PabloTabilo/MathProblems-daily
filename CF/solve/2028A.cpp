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
	int n, a, b;
	cin >> n >> a >> b;
	string p;
	cin >> p;
	unordered_map<int, int> f = {
	    {'N',0},
	    {'E',0},
	    {'W',0},
	    {'S',0}
	};
	for(char c : p){
	    f[c]++;
	}
	int x = 0;
	int y = 0;
	bool found = false;
	// is cycle
	if(f['N'] == f['S'] && f['E'] == f['W']){
	    // on the cycle exist the position of a,b?
	    // simulate the cycle
	    for(auto c : p){
		if (c == 'N') y++;
		if (c == 'S') y--;
		if (c == 'E') x++;
		if (c == 'W') x--;
		if(b == y && a == x){
		    found = true;
		    break;
		}
	    }
	}else{
	    // simulate the pattern x times?
	    // if reach a, b is correct
	    int cycle = 1;
	    while(cycle <= 1000){
		for(auto c : p){
		    if (c == 'N') y++;
		    if (c == 'S') y--;
		    if (c == 'E') x++;
		    if (c == 'W') x--;
		    if(b == y && a == x){
			found = true;
			break;
		    }
		}
		cycle++;
	    }
	}
	if(found){
	    cout << "YES\n";
	}else{
	    cout << "NO\n";
	}
    }

    return 0;
}

