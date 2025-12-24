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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> last(26,0);
    for(int i=0;i<n;i++){
	last[s[i]-'a'] = i;
    }
    int l = -1;
    int r = -1;
    for(int i=0;i<n;i++){
	char until = s[i];
	int vuntil = s[i] - 'a';
	for(int j=0;j<vuntil;j++){
	    if(last[j] > i){
		l = i;
		r = last[j];
		break;
	    }
	}
	if(l != -1 && r != -1){
	    break;
	}
    }
    if(l == -1 && r == -1){
	cout << "NO\n";
    }else{
	l++;
	r++;
	cout << "YES\n";
	cout << l << " " << r << '\n';
    }

    return 0;
}

