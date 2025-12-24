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
	string s;
	cin >> s;
	int * cnt = new int[26]();
	memset(cnt, 0, 26 * sizeof(int));
	for(auto c : s){
	    cnt[c-'a']++;
	}
	int ans = 0;
	int uniques = 0;
	for(int i=0;i<26;i++){
	    if(cnt[i] >= 2){
		ans++;
		cnt[i] = 0;
	    }else if(cnt[i] == 1){
		uniques++;
	    }
	}
	ans += (uniques / 2);
	cout << ans << '\n';
    }

    return 0;
}

