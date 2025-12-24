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
class Solution {
  public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
	//cout << "string s = " << s << endl;
        // code here
        int n = s.size();
        vector<vector<ll>> prefix(26, vector<ll>(n, 0LL));
        
        map<char, vector<int>> idxs;
	for(int i=0;i<n;i++){
	    idxs[s[i]].push_back(i);
	}

	for(int k=0;k<26;k++){
	    char except = char('a'+k);
	    for(int i=0;i<n;i++){
		if((i-1)>=0){
		    prefix[k][i] = prefix[k][i-1];
		}
		if(s[i] != except){
		    prefix[k][i] += (ll)(s[i]);
		}
	    }
	}
        
        map<char, vector<char>> g;
        for(vector<char> e : jumps){
            g[e[0]].push_back(e[1]);
        }
	
	/*
	cout << "prefix: ";
	for(int i=0;i<26;i++){
	    char c = char('a'+i);
	    cout << c << ": ";
	    for(int x : prefix[i]) cout << x << " ";
	    cout << endl;
	}
	cout << endl;
	
	cout << "idxs : " << endl;
	for(auto[k, v] : idxs){
	    cout << k << " -> {";
	    for(auto x : v){
		cout << x << " ";
	    }
	    cout << "}"<<endl;
	}
	cout << endl;
	
	cout << "g : " << endl;
	for(auto[k, v] : g){
	    cout << k << " -> {";
	    for(auto x : v){
		cout << x << " ";
	    }
	    cout << "}"<<endl;
	}
	cout << endl;
        */
	vector<ll> dp(n, -1);
        function<ll(int)> f = [&](int from){
	    if(dp[from] != -1){
		return dp[from];
	    }
            char curr = s[from];
            ll ans = 0;
	    //cout << "curr = " << curr << ", from = " << from << endl; 
            if(g.find(curr) != g.end()){
                for(char nxt: g[curr]){
		    //cout << "curr = " << curr << ", from = " << from << ", nxt = " << nxt << endl; 
                    auto it = lower_bound(idxs[nxt].begin(), idxs[nxt].end(), from);
                    if(it == idxs[nxt].end()){
                        continue;
                    }
                    int sz = idxs[nxt].size();
                    int j = it - idxs[nxt].begin();
		    //cout << "curr = " << curr << ", from = " << from << ", nxt = " << nxt << ", j = " << j << endl; 
                    for(;j<sz;j++){
                        int to = idxs[nxt][j];
			//cout << "curr = " << curr << ", from = " << from << ", nxt = " << nxt << ", j = " << j << ", to = " << to << endl; 
                        ll local = prefix[nxt-'a'][to];
                        if(from >= 1){
                            local -= prefix[nxt-'a'][from-1];
                        }   
			//cout << "curr = " << curr << ", from = " << from << ", nxt = " << nxt << ", j = " << j << ", to = " << to << endl; 
			ll recursiveCall = f(to);
                        ans = max(ans, local+recursiveCall);
			//cout << "curr = " << curr << ", from = " << from << ", nxt = " << nxt << ", j = " << j << ", to = " << to << " local = " << local << ", ans = " << ans << endl; 
                    }
                }
            }
	    //cout << "nxt same: curr = " << curr << ", from = " << from << endl; 
            auto it = lower_bound(idxs[curr].begin(), idxs[curr].end(), from);
            it++;
            if(it == idxs[curr].end()){
		//cout << "find end for curr = " << curr <<", and from = " << from << endl;
                return ans;
            }
            int sz = idxs[curr].size();
            int j = it - idxs[curr].begin();
	    //cout << "nxt same: curr = " << curr << ", from = " << from << ", j = " << j << endl; 
            for(;j<sz;j++){
                int to = idxs[curr][j];
		//cout << "nxt same: curr = " << curr << ", from = " << from << ", j = " << j << " to = " << to << endl; 
                ll local = prefix[curr-'a'][to];
                if(from >= 1){
                    local -= prefix[curr-'a'][from-1];
                }
		//cout << "nxt same: curr = " << curr << ", from = " << from << ", j = " << j << " to = " << to << endl; 
		ll recursiveCall = f(to);
                ans = max(ans, local+recursiveCall);
		//cout << "nxt same: curr = " << curr << ", from = " << from << ", j = " << j << ", to = " << to << " local = " << local << ", ans = " << ans << endl; 
            }
            return dp[from] = ans;
        };
        return f(0);
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solution sol;
    vector<vector<char>> jumps = {{'f', 'r'}, {'r', 'g'}};
    string s = "forgfg";
    int ans = sol.maxScore(s, jumps);
    cout << "ans = " << ans << endl;
    return 0;
}

