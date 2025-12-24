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
	vector<vector<int>> a(n, vector<int>(n, 0));
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
		cin >> a[i][j];
	    }
	}
	//cout << "?" << endl;
	int ans = 0;
	for(int j=n-1;j>=0;j--){
	    //cout << "j = " << j << endl;
	    int mn = INT_MAX;
	    for(int k=0;k<n-j;k++){
		//cout << "a["<<k<<"]["<<j+k<<"] = "<<a[k][j+k]<<endl;
		mn = min(mn, a[k][j+k]);
	    }
	    if(mn < 0){
		ans += abs(mn);
	    }
	}
	
	for(int i=1;i<n;i++){
	    //cout << "i = " << i << endl;
	    int mn = INT_MAX;
	    for(int k=0;k<n-i;k++){
		mn = min(mn, a[i+k][k]);
	    }
	    if(mn < 0){
		ans += abs(mn);
	    }
	}
	cout << ans << '\n';

    }

    return 0;
}

