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
	ll n, m, i, j;
	cin >> n >> m >> i >> j;
	cout << 1 << " " << 1 << " " << n << " " << m << '\n';
	/*
	set<pair<ll, pair<ll, ll>>> s;
	ll p11 = 1;
	ll p12 = 1;
	
	ll d1 = abs(i - p11) + abs(j - p12);
	//cout << "p11, p12 = " << p11 << ", " << p12 << " >> d1 = " << d1 << endl;
	s.insert({d1, {p11, p12}});

	ll p21 = 1;
	ll p22 = m;
	
	ll d2 = abs(i - p21) + abs(j - p22);
	//cout << "p21, p22 = " << p21 << ", " << p22 << " >> d2 = " << d2 << endl;
	s.insert({d2, {p21, p22}});

	ll p31 = n;
	ll p32 = 1;
	
	ll d3 = abs(i - p31) + abs(j - p32);
	//cout << "p31, p32 = " << p31 << ", " << p32 << " >> d3 = " << d3 << endl;
	s.insert({d3, {p31, p32}});

	ll p41 = n;
	ll p42 = m;

	ll d4 = abs(i - p41) + abs(j - p42);
	//cout << "p41, p42 = " << p41 << ", " << p42 << " >> d4 = " << d4 << endl;
	s.insert({d4, {p41, p42}});

	auto it = s.rbegin();
	ll a1 = (*it).second.first;
	ll a2 = (*it).second.second;
	ll b1 = a1;
	ll b2 = a2;
	it--;
	if(it != s.rend()){
	    b1 = (*it).second.first;
	    b2 = (*it).second.second;
	}
	cout << a1 << " " << a2 << " " << b1 << " " << b2;
	cout << '\n';
	//cout << endl;
	*/
    }
    return 0;
}

