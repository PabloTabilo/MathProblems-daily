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
	int n;
	cin >> n;
	int * P = new int[n];
	unordered_map<int, int> um;
	for(int i=0;i<n;i++){
	    cin >> P[i];
	    um[P[i]] = i;
	}

	int low = -1;
	int hi = n;
	int candidate = n;
	bool isPossible = false;
	int j;
	while(candidate > 2){
	    j = um[candidate];
	    if((j-1) != low && (j+1) != hi){
		isPossible = true;
		break;
	    }
	    if((j-1) == low){
		low = j;
	    }else if((j+1) == hi){
		hi = j;
	    }
	    candidate--;
	}
	if(!isPossible){
	    cout << "NO";
	    cout << '\n';
	    //cout << endl;
	    continue;
	}
	//cout << "candidate = " << candidate << ", j = " << j << endl;
	int i = j-1;
	for(i=j-1;i>=0;i--){
	    if(P[i] < P[j]){
		break;
	    }
	}
	int k = j+1;
	for(k=j+1;k<n;k++){
	    if(P[k] < P[j]){
		break;
	    }
	}
	i++;
	j++;
	k++;
	cout << "YES";
	cout << '\n';
	//cout << endl;
	cout << i << " " << j << " " << k;
	cout << '\n';
	//cout << endl;
    }
    

    return 0;
}

