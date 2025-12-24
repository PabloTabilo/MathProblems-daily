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
    string s;
    cin >> s;
    string ans;
    string t;
    int m;
    int n = (int)s.size();
    for(int i=0;i<n;i++){
	t += s[i];
	m = (int)t.size();
	if(m >= 3){
	    if(t[m-1] == 'B' && t[m-2] == 'U' && t[m-3] == 'W'){
		t.pop_back();
		t.pop_back();
		t.pop_back();
		if((int)t.size() > 0){
		    if((int)ans.size() > 0){
			ans += " ";
			ans += t;
		    }else{
			ans = t;
		    }
		}
		t = "";
	    }
	}
    }
    if((int)t.size() > 0){
	if((int)ans.size() > 0){
	    ans += " ";
	    ans += t;
	}else{
	    ans = t;
	}
    }
    //cout << "ans = ";
    cout << ans << '\n';
    //cout << endl;
    return 0;
}

