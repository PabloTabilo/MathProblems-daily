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
	ll X;
	cin >> n >> X;
	vector<ll>a(n);
	for(int i=0;i<n;i++){
	    cin >> a[i];
	}
	/*
	if(n == 1){
	    ll curr = a[0]/X;
	    if(curr == 1){
		cout << 1 << '\n';
	    }else{
		cout << 0 << '\n';
	    }
	    cout << a[0] << '\n';
	    continue;
	}
	*/
	sort(a.begin(), a.end());
	int p1 = 0;
	int p2 = n-1; // bonus
	ll ans = 0LL;
	vector<int> positions;
	ll S = 0LL;
	while(p1 <= p2){
	    ll level = S / X;
	    ll nxt = (level + 1) * X;

	    for(;p1<=p2 && S + a[p1] < nxt;p1++){
		S += a[p1];
		positions.push_back(p1);
	    }

	    if(p1 > p2) break;
	    positions.push_back(p2);
	    S += a[p2];
	    ans += a[p2];
	    p2--;
	}
	cout << ans << '\n';
	for(int idx : positions){
	    cout << a[idx] << " ";
	}
	cout << '\n';
    }
    return 0;
}

