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
	string s;
	cin >> s;
	if(n == 1){
	    cout << "YES";
	    cout << '\n';
	    //cout << endl;
	    cout << 1 << '\n';
	    continue;
	}
	if(s[0] == '0' && s[1] == '1'){
	    cout << "NO";
	    cout << '\n';
	    //cout << endl;
	    continue;
	}
	if(s[n-1] == '0' && s[n-2] == '1'){
	    cout << "NO";
	    cout << '\n';
	    //cout << endl;
	    continue;
	}

	bool possible = true;
	for(int i=1;i<n-1;i++){
	    if(s[i-1] == '1' && s[i] == '0' && s[i+1] == '1'){
		possible = false;
	    }    
	}
	if(!possible){
	    cout << "NO";
	    cout << '\n';
	    //cout << endl;
	    continue;
	}
	vector<int> ans(n);
	vector<pair<int, int>> intervals;
	int left = -1;
	for(int i=1;i<=n;i++){
	    ans[i-1] = i;
	    if(s[i-1] == '0'){
		if(left == -1){
		    left = i-1;
		}
	    }else{
		if(left != -1){
		    intervals.push_back({left, i-2});
		    left = -1;
		}
	    }
	}
	//cout << "last value of left = " << left << endl;
	//cout << "n = " << n << endl;
	if(left != -1){
	    intervals.push_back({left, n-1});
	}
	for(auto [left, right] : intervals){
	    int mn = ans[left];
	    int mx = ans[right];
	    //cout << "left vs right = " << left << " vs " << right << endl;
	    //cout << "mn vs mx = " << mn << " vs " << mx << endl;
	    while(mn < mx){
		ans[right] = mn;
		ans[left] = mx;
		mn++;
		mx--;
		left++;
		right--;
	    }
	}
	cout << "YES";
	cout << '\n';
	//cout << endl;
	for(auto x : ans){
	    cout << x << " ";
	}
	cout << '\n';
	//cout << endl;
    }
    return 0;
}

