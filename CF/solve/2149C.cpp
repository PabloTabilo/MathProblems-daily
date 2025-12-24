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
	int n, k;
	cin >> n >> k;
	vector<bool> ks(k, false);
	vector<int> a(n);
	int cnt = 0;
	int remove = 0;
	for(int i=0;i<n;i++){
	    cin >> a[i];
	    if(a[i] < k){
		if(ks[a[i]]){
		    remove++;
		}
		ks[a[i]] = true;
	    }else if(a[i] == k){
		cnt++;
	    }else{
		remove++;
	    }
	}
	int ope = cnt;
	for(int i=0;i<k;i++){
	    if(!ks[i]){
		if(cnt > 0){
		    cnt--;
		}else if(remove > 0){
		    remove--;
		    ope++;
		}	
	    }
	}
	cout << ope << '\n';
    }

    return 0;
}

