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
    int N;
    cin >> N;
    int * A = new int[N];
    for(int i=0;i<N;i++){
	cin >> A[i];
    }
    int core = A[0];
    while(core % 2 == 0){
	core /= 2;
    }
    while(core % 3 == 0){
	core /= 3;
    }
    int sumP = 0;
    int sumQ = 0;
    int pMin = INT_MAX;
    int qMin = INT_MAX;
    for(int i=0;i<N;i++){
	int ci = A[i];
	int p = 0;
	while(ci % 2 == 0){
	    ci /= 2;
	    p++;
	}
	int q = 0;
	while(ci % 3 == 0){
	    ci /= 3;
	    q++;
	}

	if(ci != core){
	    cout << "-1" << '\n';
	    return 0;
	}

	sumP += p;
	sumQ += q;
	pMin = min(pMin, p);
	qMin = min(qMin, q);
    }
    int ans = (sumP - N*pMin) + (sumQ - N*qMin);
    cout << ans << '\n';
    return 0;
}

