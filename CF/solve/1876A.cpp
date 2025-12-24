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
	ll n, P;
	cin >> n >> P;

	vector<pair<ll,ll>> residents(n);
	for(int i=0;i<n;i++){
	    ll a;
	    cin >> a;
	    residents[i] = {-1, a};
	}
	for(int i=0;i<n;i++){
	    ll b;
	    cin >> b;
	    residents[i].first = b;    
	}
	sort(residents.begin(), residents.end(), [](auto &l, auto &r){
		if(l.first == r.first){
		    return l.second > r.second;
		}
		return l.first < r.first;
	    }
	);

	n--;
	ll mnCost = P;
	//cout << "residents: ";
	for(auto p : residents){
	    //cout << "{"<<p.first<<", "<<p.second<<"} ";
	    if(n == 0){
		break;
	    }
	    ll cost = p.first;
	    if(cost >= P){
		mnCost += (P*n);
		break;
	    }
	    ll num = p.second;
	    ll diff = n-num;
	    if(diff >= 0){
		n -= num;
		mnCost += (cost*num);
	    }else{
		mnCost += (cost*n);
		n = 0;
	    }
	}
	//cout << endl;
	//cout << "mnCost = ";
	cout << mnCost;
	cout << '\n';
	//cout << endl;
    }

    return 0;
}

