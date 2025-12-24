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
	ll k, x;
	cin >> k >> x;
	ll c = 1 << k;
	ll v = 1 << k;

	ll INF = 1e12;
	vector<int> op;
	function<ll(ll, ll, vector<int>)> f = [&](ll cl, ll vl, vector<int> comb){
	    //cout << "cl = " << cl << ", vl = " << vl << ", x = " << x << '\n';
	    int n = op.size();
	    int m = comb.size();
	    if(cl != x){
		if(m > 120){
		    return INF;
		}
		ll add1 = cl/2;
		ll add2 = vl/2;
		ll op1 = INF;
		ll op2 = INF;

		if((cl%2) == 0){
		    comb.push_back(1);
		    op1 = 1LL + f(cl >> 1, vl + add1, comb);
		    comb.pop_back();
		}
		if((vl%2) == 0){
		    comb.push_back(2);
		    op2 = 1LL + f(cl + add2, vl >> 1, comb);
		    comb.pop_back();
		}
		return min(op1, op2);
	    }
	    if(n == 0 || n > m){
		op = comb;
	    }
	    return 0LL;
	};

	vector<int> comb;
	f(c, v, comb);
	cout << (int)op.size() << '\n';
	for(int i : op){
	    cout << i << " ";
	}
	cout << '\n';
    }
    return 0;
}

