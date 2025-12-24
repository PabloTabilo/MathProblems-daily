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
	char * s = new char[n];
	for(int i=0;i<n;i++){
	    cin >> s[i];
	}
	vector<bool> f(26, false);
	int * fprev = new int[n](); // freq prev inclusive
	for(int i=0;i<n;i++){
	    f[s[i]-'a']=true;
	    int cnt = 0;
	    for(int i=0;i<26;i++){
		cnt += f[i];
	    }
	    fprev[i] = cnt;
	}
	fill(f.begin(), f.end(), false);
	int * fpost = new int[n](); // freq post not inclusive
	for(int i=n-2;i>=0;i--){
	    f[s[i+1]-'a']=true;
	    int cnt = 0;
	    for(int i=0;i<26;i++){
		cnt += f[i];
	    }
	    fpost[i] = cnt;
	}
	ll ans = 0;
	for(int i=0;i<n-1;i++){
	    ll local = (ll)fprev[i] + (ll)fpost[i];
	    ans = max(ans, local);
	}
	cout << ans << '\n';
	
    }

    return 0;
}

