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
	ll n, p;
	cin >> n >> p;
	vector<ll> A(n);
	vector<ll> B(n);
	vector<pair<ll, ll>> r(n);
	for(int i=0;i<n;i++){
	    cin >> A[i];
	}
	for(int i=0;i<n;i++){
	    cin >> B[i];
	}
	for(int i=0;i<n;i++){
	    r[i] = make_pair(B[i], A[i]);
	}
	sort(r.begin(), r.end(), [](auto &lo, auto &hi){
		if(lo.first == hi.first){
		return lo.second < hi.second;
		}
	    return lo.first < hi.first; 	
	});

	//cout << "r: ";
	//for(auto p : r){
	//    cout << "{"<< p.first << "," << p.second <<"} ";
	//}
	//cout << endl;

	ll cost = p;
	ll cnt = 1;
	for(int i=0;i<n;i++){
	    auto [b, a] = r[i];
	    if((n-cnt) == 0){
		break;
	    }
	    ll diff = n - cnt;
	    ll addMe;
	    if(p <= b){
		addMe = diff;
		cost += (addMe * p);
		cnt += addMe;
		break;
	    }
	    addMe = min(diff, a);
	    cost += (addMe * b);
	    cnt += addMe;
	}
	//cout << "cost = ";
	cout << cost;
	cout << '\n';
	//cout << endl;
    }
    return 0;
}

