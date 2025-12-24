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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	function<bool(string)> isPalindrome = [](string s){
	    int p1 = 0;
	    int p2 = s.size()-1;
	    while(p1 < p2){
		if(s[p1] != s[p2]) return false;
		p1++;
		p2--;
	    }
	    return true;
	};
	while(k > 0){
	    //cout << "current s = " << s << endl;
	    if(isPalindrome(s)){
		s += s.back();
		k--;
		// is palindrome again? so t1 = t2 = ... = tm;
		if(isPalindrome(s)){
		    s.append(k, s.back());
		    k = 0;
		}
	    }else{
		s.resize(s.size() / 2);
		k--;
	    }
	    //cout << "new s = " << s << endl;
	}
	//cout << "final: ";
	cout << s << '\n';
    }

    return 0;
}

