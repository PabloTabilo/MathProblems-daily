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
    ll n;
    cin >> n;
    ll * A = new ll[n];
    for(ll i=0;i<n;i++){
	cin >> A[i];
    }
    ll x = *max_element(A, A + n);
    ll z = 0;
    for(int i=0;i<n;i++){
	ll d = x - A[i];
	if(d > 0) z = __gcd(z, d);
    }
    ll y = 0;
    for(ll i=0;i<n;i++){
	y += (x - A[i])/z;
    }
    /*
    cout << "x = " << x << '\n';
    cout << "y = " << y << '\n';
    cout << "z = " << z << '\n';
    */
    cout << y << " " << z << '\n';
    return 0;
}

