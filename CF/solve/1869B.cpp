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
	int N, K, A, B;
	cin >> N >> K >> A >> B;
	vector<pair<ll,ll>> P(N);
	for(int i=0;i<N;i++){
	    ll x, y;
	    cin >> x >> y;
	    P[i] = {x, y};
	}
	A--;
	B--;
	const ll INF = 1e12;
	auto dist = [&](int p1, int p2) -> ll{
	    return llabs(P[p1].first - P[p2].first) + llabs(P[p1].second - P[p2].second);
	};

	ll directCost = dist(A, B);
	if(K == 0){
	    cout << directCost;
	    cout << '\n';
	    continue;
	}

	if( A < K && B < K ){
	    directCost = 0;
	}
	ll bestA = (A < K ? 0 : INF);
	ll bestB = (B < K ? 0 : INF);
	if(A >= K){
	    for(int i=0;i<K;i++){
		bestA = min(bestA, dist(A, i));
	    }
	}
	if(B >= K){
	    for(int i=0;i<K;i++){
		bestB = min(bestB, dist(B, i));
	    }
	}
	ll clus = bestA + bestB;
	ll ans = min(clus, directCost);
	cout << ans;
	cout << '\n';
    }

    return 0;
}

