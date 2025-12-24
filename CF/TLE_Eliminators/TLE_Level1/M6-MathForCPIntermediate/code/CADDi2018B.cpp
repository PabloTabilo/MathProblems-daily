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
    ll N, P;
    cin >> N >> P;
    if(P == 1){
	cout << 1 << '\n';
	return 0;
    }
    if(N == 1){
	cout << P << '\n';
	return 0;
    }
    vector<ll> factors;
    for(ll i = 2; i*i <= P; i++){
	while(P % i == 0){
	    P /= i;
	    factors.push_back(i);
	}
    }
    if(P > 1){
	factors.push_back(P);
    }
    int m = factors.size();
    if(N > m){
	cout << 1 << '\n';
	return 0;
    }
    //cout << "factors: "; for(auto x : factors) cout << x << " "; cout << '\n';
    vector<ll> A(N, 1LL);
    int i = 0;
    while(factors.size() > 0){
	ll last = factors.back();
	factors.pop_back();
	A[i] = A[i] * last;
	i = (i + 1) % N;
    }
    //cout << "A: "; for(auto x : A) cout << x << " "; cout << '\n';
    ll g = -1;
    for(ll x : A){
	if(g == -1){
	    g = x;
	}else{
	    g = __gcd(g, x);
	}
    }
    cout << g << '\n';
    return 0;
}

