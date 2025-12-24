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
    bool debugme = false;
    cin >> t;
    while(t--){
	int n, k;
	cin >> n >> k;
	int * A = new int[n];
	vector<int> diff(n,0);
	for(int i=0;i<n;i++){
	    cin >> A[i];
	}
	sort(A, A+n);
	if(debugme){
	    cout << "sorted: ";
	    for(int i=0;i<n;i++){
		cout << A[i] << " ";
	    }
	    cout << endl;
	}
	for(int i=1;i<n;i++){
	    diff[i] = abs(A[i] - A[i-1]);
	}
	if(debugme){
	    cout << "consecutive diff: ";
	    for(int i=1;i<n;i++){
		cout << diff[i] << " ";
	    }
	    cout << endl;
	}
	int ans = INT_MAX;
	int cnt = 1;
	for(int i=1;i<n;i++){
	    int x = diff[i];
	    if(x <= k){
		cnt++;
	    }else{
		if(debugme) cout << "cnt = " << cnt << endl;
		ans = min(ans, n-cnt);
		cnt = 1;
	    }
	}
	if(debugme) cout << "last cnt = " << cnt << endl;
	ans = min(ans, n-cnt);
	if(debugme) cout << "ans = ";
	cout << ans << '\n'; 
	//cout << endl;
	if(debugme) cout << "-------------" << endl;
    }

    return 0;
}

