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
    int A, B, K;
    cin >> A >> B >> K;
    int g = __gcd(A, B);
    ordered_set<int> s;
    for(int i=1;i*i <= g; i++){
	if(g % i == 0){
	    s.insert(i);
	    s.insert(g / i);
	}
    }
    //cout << "s: "; for(auto x : s) cout << x << " ";
    int sz = s.size();
    int ans = *(s.find_by_order( sz - K ));
    //cout << "\nans = ";
    cout << ans << '\n';
    return 0;
}

