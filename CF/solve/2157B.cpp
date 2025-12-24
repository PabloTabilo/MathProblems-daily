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
	int n, xl, yl;
	cin >> n >> xl >> yl;
	string s;
	cin >> s;
	set<pair<int, int>> b;
	b.insert({0,0});
	auto exist = [&](int nx, int ny){
	    return b.find({nx, ny}) != b.end();
	};
	auto allNeightAreBlack = [&](int x, int y){
	    return exist(x+1, y) && exist(x-1, y) && exist(x, y+1) && exist(x, y-1) && exist(x+1, y+1) && exist(x+1, y-1) && exist(x-1, y+1) && exist(x-1, y-1);
	};
	bool found = false;
	for(char c : s){
	    vector<pair<int, int> > curr(b.begin(), b.end());
	    for(auto [x, y] : curr){
		if(allNeightAreBlack(x, y)){
		    b.erase({x, y});
		    continue;
		}
		b.insert({x+1, y});
		b.insert({x-1, y});
		b.insert({x, y+1});
		b.insert({x, y-1});
		if(c == '8'){
		    b.insert({x+1, y+1});
		    b.insert({x+1, y-1});
		    b.insert({x-1, y+1});
		    b.insert({x-1, y-1});
		}
	    }
	    if(b.find({xl, yl}) != b.end()){
		found = true;
		break;
	    }
	}
	if(found){
	    cout << "YES";
	}else{
	    cout << "NO";
	}
	cout << '\n';
    }

    return 0;
}

