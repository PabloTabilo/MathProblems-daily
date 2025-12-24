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
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int num = 1;
	int * P = new int[n]();
	for(int i=0;i<n;i++){
	    if(s[i] == '1'){
		P[i] = num;
		num++;
	    }
	}
	for(int i=0;i<n;i++){
	    if(s[i] == '0'){
		P[i] = num;
		num++;
	    }
	}
	//cout << "P: ";	
	//for(int i=0;i<n;i++){
	//    cout << P[i] << " ";
	//}
	//cout << endl;
	bool impossible = false;
	int r = 0;
	multiset<pair<int, int>> ms;
	for(int l=0;l<(n-k+1);l++){
	    while(r < n && (r - l + 1) <= k){
		ms.insert({P[r], r});
		r++;
	    }
	    //cout << "l, r = " << l << "," << r << endl;
	    //for(auto x : ms){
		//cout << "{"<<x.first << ", "<<x.second << "} ";
	    //}
	    //cout << endl;
	    auto [mx, idx] = *ms.rbegin();
	    if(s[idx] == '1'){
		impossible = true;
		break;
	    }
	    auto it = ms.find({P[l], l});
	    ms.erase(it);
	}

	if(!impossible){
	    cout << "YES\n";
	    for(int i=0;i<n;i++){
		cout << P[i] << " ";
	    }
	}else{
	    cout << "NO";
	}
	cout << '\n';
    }

    return 0;
}

