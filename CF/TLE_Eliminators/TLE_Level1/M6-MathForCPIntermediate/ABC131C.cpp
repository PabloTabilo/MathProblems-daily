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
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    set<ll> s;
    ll t1 = ( A % C == 0 ? A/C : (A/C) + 1);
    ll t2 = ( A % D == 0 ? A/D : (A/D) + 1);

    cout << "t1 = " << t1 << '\n';
    cout << "t2 = " << t2 << '\n';

    while(C*t1 <= B){
	s.insert(C*t1);
	t1++;
    }
    
    while(D*t2 <= B){
	s.insert(D*t2);
	t2++;
    }
    ll sz = s.size();
    ll ans = (B - A + 1) - sz;
    cout << ans << '\n';
    return 0;
}

