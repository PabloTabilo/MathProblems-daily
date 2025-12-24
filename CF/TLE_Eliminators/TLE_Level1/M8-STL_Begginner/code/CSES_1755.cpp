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
    int n = s.size();
    if(n == 1){
	cout << s << '\n';
	return 0;
    }
    int * cnt = new int[26]();
    for(auto c : s){
	cnt[c-'A']++;
    }
    int numOdds = 0;
    for(int i=0;i<26;i++){
	if(cnt[i] % 2 != 0){
	    numOdds++;
	}
    }
    if(numOdds > 1){
	cout << "NO SOLUTION\n";
	return 0;
    }
    int p1 = 0;
    int p2 = n-1;
    for(int i=0;i<26;i++){
	char ch = i + 'A';
	while(cnt[i] >= 2){
	    s[p1] = ch;
	    s[p2] = ch;
	    p1++;
	    p2--;
	    cnt[i] -= 2;
	}
    }
    for(int i=0;i<26;i++){
	if(cnt[i] == 1){
	    s[n/2] = char(i + 'A');
	    break;
	}
    }
    cout << s << '\n';
    return 0;
}

