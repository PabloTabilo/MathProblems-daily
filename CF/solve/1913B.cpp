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
	int n = s.length();
	int cnt0s = 0;
	int cnt1s = 0;
	if(n == 1){
	    cout << 1;
	    //cout << endl;
	    cout << '\n';
	    continue;
	}
	for(char c : s){
	    if(c == '0'){
		cnt0s++;
	    }
	    if(c == '1'){
		cnt1s++;
	    }
	}
	if(cnt0s == cnt1s){
	    cout << 0;
	    //cout << endl;
	    cout << '\n';
	    continue;
	}
	string t = s;
	for(int i=0;i<n;i++){
	    if(t[i] == '0' && cnt1s > 0){
		t[i] = '1';
		cnt1s--;
	    }else if(t[i] == '1' && cnt0s > 0){
		t[i] = '0';
		cnt0s--;
	    }
	}
	//cout << "swaps 0 cost >> t = " << t << endl;
	int cost = 0;
	int last = n;
	for(int i=n-1;i>=0;i--){
	    if(s[i] != t[i]){
		continue;
	    }
	    else{
		last = i;
	    }
	}
	cost = n - last;
	//cout << "cost = "; 
	cout << cost;
	cout << '\n';
	//cout << endl;
    }

    return 0;
}

