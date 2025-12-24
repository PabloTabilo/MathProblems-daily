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
	ll a, b;
	cin >> a >> b;
	if(a == b){
	    cout << 0;
	    cout << '\n';
	    //cout << endl;
	    continue;
	}
	ll g = gcd(a, b);
	if(g == 1 && min(a, b) != 1){
	    cout << -1;
	    //cout << endl;
	    cout << '\n';
	    continue;
	}
	a /= g;
	b /= g;
	//cout << "g = " << g << endl;
	//cout << "a = " << a << ", b = " << b << endl;
	if(a != 1 && b != 1){
	    cout << -1;
	    //cout << endl;
	    cout << '\n';
	    continue;
	}
	if(a < b){
	    swap(a, b);
	}
	ll ope = 0;
	bool impossible = false;
	while(a > 1 && a != b){
	    if(a < b){
		swap(a, b);
	    }
	    while(a >= 8 && a % 8 == 0){
		a /= 8;
		ope++;
	    }
	    while(a >= 4 && a % 4 == 0){
		a /= 4;
		ope++;
	    }
	    while(a >= 2 && a%2 == 0){
		a /= 2;
		ope++;
	    }
	    if(a > 1 && a % 2 != 0){
		impossible = true;
		break;
	    }
	}
	if(impossible){
	    cout << -1;
	    cout << '\n';
	    continue;
	}
	//cout << "ope = ";
	cout << ope;
	//cout << endl;
	cout << '\n';
    }

    return 0;
}

