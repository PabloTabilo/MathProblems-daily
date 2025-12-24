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
    ll t1 = ( A % C == 0 ? A/C : (A/C) + 1);
    ll t2 = ( A % D == 0 ? A/D : (A/D) + 1);

    //cout << "A, C >> t1 = " << t1 << '\n';
    //cout << "A, D >> t2 = " << t2 << '\n';

    ll t3 = B / C;
    ll t4 = B / D;

    //cout << "B, C >> t3 = " << t3 << '\n';
    //cout << "B, D >> t4 = " << t4 << '\n';

    ll g = __gcd(C, D);
    //cout << "gcd = " << g << '\n';
    ll l = C/g * D;
    //cout << "lcm = " << l << '\n';
    ll t5 = ( A % l == 0 ? A/l : (A/l) + 1);
    ll t6 = B / l;

    //cout << "A, lcm >> t5 = " << t5 << '\n';
    //cout << "B, lcm >> t6 = " << t6 << '\n';

    ll contribution1 = t3 - t1 + 1;
    ll contribution2 = t4 - t2 + 1;
    ll collisions = (t6 >= t5 ? t6 - t5 + 1 : 0);


    ll ans = (B - A + 1) - (contribution1 + contribution2 - collisions);
    cout << ans << '\n';
    return 0;
}

