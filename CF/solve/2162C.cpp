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
	int a, b;
	cin >> a >> b;
	if(a == b){
	    cout << 0 << '\n';
	    continue;
	}
	int ca = a;
	vector<int> ans;
	int prev = 0;
	for(int i = 0; i<32;i++){
	    int mask = (1 << i);
	    int bitA = a&mask;
	    int bitB = b&mask;
	    if(bitA != bitB){
		//cout << "prev a = " << a << ", mask = " << mask << "prev prev = " << prev << '\n';
		if(prev+mask > a){
		    ans.push_back(prev);
		    prev = mask;
		    a = a ^ prev;
		}else{
		    prev = prev | mask;
		}
		//cout << "new a = " << a << ", b = " << b << ", prev = "<<prev<<'\n';
	    }
	}
	ans.push_back(prev);
	bool ok = true;
	for(int x : ans){
	    if(x > ca){
		ok = false;
	    }
	    ca = ca ^ x;
	}
	if(ok){
	    cout << (int)ans.size() << '\n';
	    for(auto x : ans){
		cout << x << " ";
	    }
	}else{
	    cout << -1;
	}
	cout << '\n';
    }

    return 0;
}

