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
    int test;
    cin >> test;
    while(test--){
	string s, t, p;
	cin >> s;
	cin >> t;
	cin >> p;
	int ns = s.size();
	int nt = t.size();
	int ht[26] = {0};
	int j = 0;
	for(int i=0;i<nt;i++){
	    ht[t[i]-'a']++;
	    if(s[j] == t[i]){
		j++;
		ht[t[i]-'a']--;
	    }
	}
	//cout << "ht: "; for(int i=0;i<26;i++) cout << ht[i] << " "; cout << endl;
	//cout << "j = " << j << endl;
	//cout << "ns = " << ns << endl;
	//cout << "nt = " << nt << endl;
	// not exists pattern s on same order on t
	if(j < ns){
	    cout << "NO\n";
	    continue;
	}
	int np = p.size();
	//cout << "np = " << np << endl;
	for(int i=0;i<np;i++){
	    if(ht[p[i]-'a'] > 0){
		ht[p[i]-'a']--;
	    }
	}
	//cout << "clear >> ht: "; for(int i=0;i<26;i++) cout << ht[i] << " "; cout << endl;
	bool isPossible = true;
	for(int i=0;i<26;i++){
	    if(ht[i] > 0){
		isPossible = false;
		break;
	    }
	}
	if(isPossible){
	    cout << "YES\n";
	}else{
	    cout << "NO\n";
	}
    }

    return 0;
}

