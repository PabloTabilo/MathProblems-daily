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
	int * sz = new int[n];
	unordered_map<int, int> um;
	unordered_map<int, pair<int, int>> idxs;
	vector<int> ans(n, -1);
	for(int i=0;i<n;i++){
	    cin >> sz[i];
	    um[sz[i]]++;
	    if(idxs.find(sz[i]) == idxs.end()){
		idxs[sz[i]] = {INT_MAX, -1};
	    }
	    idxs[sz[i]].first = min(idxs[sz[i]].first, i);
	    idxs[sz[i]].second = max(idxs[sz[i]].second, i);
	}
	bool impossible = false;
	for(auto [k, f]: um){
	    if(f == 1){
		impossible = true;
		break;
	    }else if(f % 2 == 0){
		auto [start, end] = idxs[k];
		for(int i=start;i<end;i++){
		    if(ans[i] != -1){
			continue;
		    }
		    ans[i] = i+1;
		    ans[i+1] = i;
		}
	    }else{
		auto [start, end] = idxs[k];
		for(int i=start+1;i<=end;i++){
		    ans[i] = i-1;
		}
		ans[start] = end;
	    }
	}
	if(impossible){
	    cout << -1;
	}else{
	    //cout << "ans: ";
	    for(int x : ans){
		cout << x+1 << " ";
	    }
	}
	//cout << endl;
	cout << '\n';
    }


    return 0;
}

