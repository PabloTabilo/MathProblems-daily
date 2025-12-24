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
	string s;
	cin >> s;
	string t = s.substr(1);
	int n = t.size();
	stack<char> stk;
	int cnt = 0;
	bool existOther = false;
	for(int i=0;i<n;i++){
	    if(t[i] == '('){
		stk.push('(');
	    }else{
		if(stk.empty()){
		    cnt++;
		    continue;
		}
		if(cnt == 1 && !existOther){
		    existOther = true;
		    cnt++;
		}
		if(stk.top() == '('){
		    stk.pop();
		}
	    }
	}
	if(cnt > 1){
	    cout << "YES\n";
	}else{
	    cout << "NO\n";
	}
    }
    return 0;
}

