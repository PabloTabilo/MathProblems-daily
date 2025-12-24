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
    for(int scenario = 1; scenario <= t; scenario++){
	int n, rows;
	cin >> n >> rows;
	bool isPossible = true;
	unordered_map<int, set<int> > h;
	while(rows--){
	    int idStudent, subject;
	    cin >> idStudent >> subject;
	    if(h.count(idStudent) > 0 && h[idStudent].count(subject) > 0){
		isPossible = false;
	    }
	    h[idStudent].insert(subject);
	}
	cout << "Scenario #"<< scenario <<": ";
	if(isPossible){
	    cout << "possible\n";
	}else{
	    cout << "impossible\n";
	}
    }

    return 0;
}

