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
	ll W, H;
	cin >> W >> H;
	int n;
	cin >> n;
	vector<ll> y0(n);
	for(int i=0;i<n;i++){
	    cin >> y0[i];
	}
	cin >> n;
	vector<ll> yH(n);
	for(int i=0;i<n;i++){
	    cin >> yH[i];
	}
	cin >> n;
	vector<ll> x0(n);
	for(int i=0;i<n;i++){
	    cin >> x0[i];
	}
	cin >> n;
	vector<ll> xW(n);
	for(int i=0;i<n;i++){
	    cin >> xW[i];
	}
	ll bestY0 = abs(y0.back()-y0[0])*H;
	ll bestYH = abs(yH.back()-yH[0])*H;
	ll bestX0 = abs(x0.back()-x0[0])*W;
	ll bestXW = abs(xW.back()-xW[0])*W;
	ll ans = max(bestY0, max(bestYH, max(bestX0, bestXW)));
	cout << ans << '\n';
    }
    return 0;
}

