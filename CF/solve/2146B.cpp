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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> sets(n);
	int * f = new int[m+1]();
	string line;
	getline(cin, line); // '\n'
	for(int i=0;i<n;i++){
	    getline(cin, line);
	    while(line.size() == 0) getline(cin, line);
	    istringstream iss(line);
	    int li;
	    iss >> li;
	    sets[i].resize(li);
	    for(int j=0;j<li;j++){
		int x;
		iss >> x;
		sets[i][j] = x;
		f[x]++;
	    }
	}
	bool isPossible = true;
	for(int i=1;i<=m;i++){
	    if(f[i] == 0){
		isPossible = false;
		break;
	    }
	}

	if(!isPossible){
	    cout << "NO\n";
	    continue;
	}

	int k = 0;
	for(int i=0;i<n;i++){
	    int sz = sets[i].size();
	    bool hasUnique = false;
	    for(int j=0;j<sz;j++){
		int x = sets[i][j];
		if(f[x] == 1){
		    hasUnique = true;
		    break;
		}
	    }
	    if(!hasUnique){
		k++;
	    }
	}
	// una forma siempre factible:
	// 1. ELEGIR TODOS LOS SETS
	if(k>=2){
	    cout << "YES\n";
	}else{
	    cout << "NO\n";
	}

    }

    return 0;
}

