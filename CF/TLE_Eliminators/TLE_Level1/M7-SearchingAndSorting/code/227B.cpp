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
    int n;
    cin >> n;
    int limit = 1e5 + 1;
    int * A = new int[limit];
    for(int i=0;i<n;i++){
	int a;
	cin >> a;
	A[a] = i;
    }
    int m;
    cin >> m;
    ll s1 = 0;
    ll s2 = 0;
    while(m--){
	int b;
	cin >> b;
	ll c1 = (ll)A[b] + 1LL;
	ll c2 = (ll)n - (ll)A[b];
	s1 += c1;
	s2 += c2;
	//cout << "b = " << b << ", A[b] = " << A[b] << endl;
	//cout << "c1 = " << c1 << ", c2 = " << c2 << endl;
    }
    cout << s1 << " " << s2 << '\n';
    // cout << endl;

    return 0;
}

