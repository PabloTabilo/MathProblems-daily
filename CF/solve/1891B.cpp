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
	int N, Q;
	cin >> N >> Q;
	vector<ll> A(N);
	for(int i=0;i<N;i++){
	    cin >> A[i];
	}
	vector<ll> raw(Q);
	for(int i=0;i<Q;i++){
	    cin >> raw[i];
	}
	
	set<ll> seen;
	vector<ll> v;
	for(auto x : raw){
	    if(seen.find(x) == seen.end()){
		v.push_back(x);
		seen.insert(x);
	    }
	}

	vector<ll> add(31, 0LL);
	for(ll e=0;e<=30;e++){
	    ll curr = e;
	    ll addMe = 0;
	    for(auto x : v){
		if(curr >= x){
		    addMe += (1LL << (x-1));
		    curr = x - 1;
		}
	    }
	    add[e] = addMe;
	}

	for(int i=0;i<N;i++){
	    ll a = A[i];
	    ll e = 0;
	    while((a & 1) == 0){
		a >>= 1;
		e++;
	    }
	    A[i] += add[e];
	}

	//cout << "A: ";
	for(auto x : A){
	    cout << x << " ";
	}
	//cout << endl;
	cout << '\n';
    }

    return 0;
}

