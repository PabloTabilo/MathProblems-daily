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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m, 0));
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
		char x;
		cin >> x;
		if(x == '#'){
		    grid[i][j] = 1;
		}
	    }
	}
	/*
	cout << "grid: "<<endl;
	for(auto x : grid){
	    for(auto y : x){
		cout << y << " ";
	    }
	    cout << endl;
	}
	cout << endl;
	*/
	int mx = 0;
	int row = 0;
	int col = 0;
	for(int i=0;i<n;i++){
	    int l = -1;
	    int r = -1;
	    for(int j=0;j<m;j++){
		if(l == -1 && grid[i][j] == 1){
		    l = j;
		}
		if(grid[i][j] == 1){
		    r = j;
		}
	    }
	    //cout << "l, r = " << l << ", " << r << endl;
	    if(l == r && l == -1){
		continue;
	    }
	    int sz = r - l + 1;
	    int mid = l + (r - l)/2;
	    if(mx < sz){
		mx = sz;
		row = i;
		col = mid;
	    }
	}
	row++;
	col++;
	cout << row << " " << col << '\n';
    }
    return 0;
}

