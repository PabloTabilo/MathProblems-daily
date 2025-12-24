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
	string a, b;
	cin >> a;
	cin >> b;
	int n = a.length();
	int m = b.length();
	int LIM = 1e9;
	vector<vector<vector< vector<int> > >> dp(
		n, 
		vector<vector<vector<int>>>(n,
		    vector<vector<int>>(m, 
			vector<int>(m, -1)
			)
		)
	);
	function<int(int, int, int, int)> f = [&](int i1, int i2, int j1, int j2){
	    if(i1 > i2){
		if((j2-j1) < 0) return LIM;
		return j2-j1+1;
	    }
	    if(j1 > j2){
		if((i2-i1) < 0) return LIM;
		return i2-i1+1;
	    }
	    int &res = dp[i1][i2][j1][j2];
	    if(res != -1){
		return res;
	    }
	    string a1 = a.substr(i1, i2 - i1 + 1);
	    string b1 = b.substr(j1, j2 - j1 + 1);
	    if(a1 == b1){
		return 0;
	    }
	    int op1 = 1 + f(i1+1, i2, j1, j2);
	    int op2 = 1 + f(i1, i2-1, j1, j2);
	    int op3 = 1 + f(i1, i2, j1+1, j2);
	    int op4 = 1 + f(i1, i2, j1, j2-1);
	    return res = min(op1, min(op2, min(op3, op4)));
	};
	int ans = f(0,n-1,0,m-1);
	//cout << "ans: ";
	cout << ans;
	cout << '\n';
	//cout << endl;
    }

    return 0;
}

