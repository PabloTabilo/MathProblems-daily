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
	string s;
	cin >> s;
	bool ok = false;
	vector<int> ans;
	for(int mask = 0; (mask < (1 << n)-1) && !ok;mask++){
	    vector<int> p;
	    string x;
	    for(int i=0;i<n;i++){
		if((1<<i)&mask){
		    p.push_back(i);
		}else{
		    x += s[i];
		}
	    }
	    int sz = x.length();
	    string leftStr = x.substr(0, (sz/2));
	    string rightStr = x.substr((sz/2)+(sz%2), (sz/2));
	    reverse(leftStr.begin(), leftStr.end());
	    if(leftStr == rightStr){
		int sz2 = p.size();
		ok = true;
		if(sz2 == 0){
		    break;
		}
		for(int j=1;j<sz2;j++){
		    if(s[p[j-1]] > s[p[j]]){
			ok = false;
			break;
		    }
		}
		if(ok){
		    for(int idx : p){
			ans.push_back(idx+1);
		    }
		}
	    }
	}
	cout << (int)ans.size() << '\n';
	for(int x : ans){
	    cout << x << " ";
	}
	cout << '\n';
    }
    return 0;
}

