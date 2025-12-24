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
	ll n;
	cin >> n;
	if(n % 25 == 0){
	    cout << 0;
	    //cout << endl;
	    cout << '\n';
	    continue;
	}
	string t = to_string(n);
	ll d = (ll)t.size();
	int LIM = 1e9 + 1;
	auto isDivBy25 = [&](int mask){
	    string nt = "";
	    for(int i=0;i<d;i++){
		if((mask & (1<<i)) != 0){
		    nt += t[i];
		}
	    }
	    //cout << "mask = " << mask << ", nt = " << nt << endl;
	    ll num = stoll(nt);
	    return (num%25) == 0;
	};

	auto isLeadingZeros = [&](int mask, int r){
	    for(int i=0;i<r;i++){
		if( (mask & (1<<i)) != 0 ){
		    return false;
		}
	    }
	    return true;
	};
	int msk = (1 << d)-1;
	vector<int> dp(msk+1, -1);
	function<int(int)> f = [&](int mask){
	    if(mask == 0){
		return LIM;
	    }
	    if (isDivBy25(mask)){
		return 0;
	    }
	    int &res = dp[mask];
	    if(res != -1){
		return dp[mask];
	    }
	    int mn = LIM;
	    for(int i=0;i<d;i++){
		if( (mask & (1 << i)) != 0){
		    vector<int> noLeadingZeros;
		    if((i+1)<d && t[i] != '0' && t[i+1] == '0'){
			if(isLeadingZeros(mask, i)){
			    int j = i+1;
			    while(j<d && t[j] == '0'){
				noLeadingZeros.push_back(j);
				j+=1;
			    }
			}
		    }
		    int sz = noLeadingZeros.size();
		    if(sz > 0){
			for(int j : noLeadingZeros){
			    mask ^= (1<<j);
			}
		    }
		    int op = 1 + f(mask ^ (1 << i));
		    mn = min(mn, op);
		    if(sz > 0){
			for(int j : noLeadingZeros){
			    mask ^= (1<<j);
			}
		    }
		}
	    }
	    return res = mn;
	};
	int ans = f(msk);
	//cout << "ans = ";
	cout << ans;
	//cout << endl;
	cout << '\n';
    }

    return 0;
}

