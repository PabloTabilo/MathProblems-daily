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
	vector<int>a(n, 0);
	vector<int>b(n, 0);
	int cnt1a = 0, cnt1b = 0;
	for(int i=0;i<n;i++){
	    cin >> a[i];
	    if(a[i] == 1){
		cnt1a++;
	    }
	}
	for(int i=0;i<n;i++){
	    cin >> b[i];
	    if(b[i] == 1){
		cnt1b++;
	    }
	}
	for(int turns=1;turns<=n;turns++){
	    int i = turns-1;
	    if(a[i] == b[i]) continue;
	    if(turns%2 == 1){
		//play A
		// iam lost
		if(cnt1a%2 == 0){
		    // he is won
		    if(cnt1b%2 == 1){
			if(a[i] == 0 && b[i] == 1){
			    cnt1a++;
			    cnt1b--;
			}else{
			    cnt1a--;
			    cnt1b++;
			}
		    }
		    // tie if both even to both odds, not important
		}
	    }else{
		//play B
		// B lose
		if(cnt1b%2 == 0){
		    // A is won
		    if(cnt1a%2 == 1){
			if(a[i] == 0 && b[i] == 1){
			    cnt1a++;
			    cnt1b--;
			}else{
			    cnt1a--;
			    cnt1b++;
			}
		    }
		    // tie if both even to both odds, not important
		}
	    }
	}
	int p1 = cnt1a%2;
	int p2 = cnt1b%2;
	if(p1 == p2){
	    cout << "Tie";
	}else if(p1 > p2){
	    cout << "Ajisai";
	}else{
	    cout << "Mai";
	}
	cout << '\n';
    }

    return 0;
}

