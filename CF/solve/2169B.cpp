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
	string s;
	cin >> s;
	int n = s.length();
	map<char, int> cnt = {{'<', 0}, {'>', 0}, {'*', 0}};
	char cur;
	char prev = '.';
	char nxt = '.';
	bool isInfinite = false;
	for(int i=0;i<n;i++){
	    cur = s[i];
	    if((i+1)>=n){
		nxt = '.';
	    }else{
		nxt = s[i+1];
	    }
	    cnt[cur]++;
	    if(prev != '.'){
		if(cur == prev && cur == '*'){
		    isInfinite = true;
		}
		if(prev == '>' && cur == '<'){
		    isInfinite = true;
		}
		if(prev == '>' && cur == '*' && nxt == '<'){
		    isInfinite = true;
		}
		if(prev == '>' && cur == '*'){
		    isInfinite = true;
		}
		if(prev == '*' && cur == '<'){
		    isInfinite = true;
		}
	    }
	    prev = cur;
	}
	if(isInfinite){
	    cout << -1;
	    //cout << endl;
	    cout << '\n';
	    continue;
	}
	if(cnt['>'] == cnt['<'] && cnt['>'] == 0 && cnt['*'] == 1){
	    cout << 1;
	    //cout << endl;
	    cout << '\n';
	    continue;
	}
	if(s[0] == '>' && s[n-1] == '<'){
	    cout << -1;
	    //cout << endl;
	    cout << '\n';
	    continue;
	}
	int ans = max(cnt['>'], cnt['<']) + cnt['*'];
	cout << ans;
	//cout << endl;
	cout << '\n';
    }
    return 0;
}

