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
    int MYLIMIT = 3e5 + 1;
    int * dp = new int[MYLIMIT]();
    for(int i=1;i<MYLIMIT;i++){
	dp[i] = dp[i-1]^i;
    }
    int t;
    cin >> t;
    while(t--){
	int a, b;
	cin >> a >> b;
	int xorv = dp[a-1];
	//cout << "a, b = " << a << "," << b << '\n';
	//cout << "xorv = " << xorv << '\n';
	if(xorv == b){
	    cout << a << '\n';
	}else{
	    int x = b ^ xorv;
	    //cout << "x = " << x << '\n';
	    if(x == a) cout << (a+2) << '\n';
	    else cout << (a+1) << '\n';
	}
    }

    return 0;
}

