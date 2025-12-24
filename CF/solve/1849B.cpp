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

struct Cmp{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
	if(a.first == b.first){
	    return a.second > b.second;
	}
	return a.first < b.first;
    }
};

template<class PQ>
void debug_pq(PQ pq){
    cout << "pq: ";
    while(!pq.empty()){
	auto p = pq.top();
	cout << "{"<<p.first<<","<<p.second<<"} ";
	pq.pop();
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	ll n, k;
	cin >> n >> k;
	vector<pair<ll, int>> monsters(n);
	for(int i=0;i<n;i++){
	    ll a;
	    cin >> a;
	    ll mod = a % k;
	    if(mod == 0){
		mod = k;
	    }
	    monsters[i] = {mod, i+1};
	}
	sort(monsters.begin(), monsters.end(), [](const auto& l, const auto& r){
		if(l.first != r.first){
		    return l.first > r.first;
		}
		return l.second < r.second;
		});
	for(auto x : monsters){
	    cout << x.second << " ";
	}	
	cout << '\n';
    }

    return 0;
}

