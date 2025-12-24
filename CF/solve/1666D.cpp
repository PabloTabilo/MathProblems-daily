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
	string s1, s2;
	cin >> s1 >> s2;
	if(s1 == s2){
	    cout << "YES\n";
	    continue;
	}
	int n = s1.length();
	int m = s2.length();

	vector<char> ope;
	unordered_map<char, vector<int>> charToidx;

	for(int i=n-1;i>=0;i--){
	    charToidx[s1[i]].push_back(i);
	}

	//for(auto[k, v] : charToidx){cout << "k = " << k << ", v = ";for(auto w : v) cout << w << " "; cout << endl;}
	
	int i=n-1;
	int j=m-1;
	while(i >= 0 && j >= 0){
	    while(i >= 0 && s2[j] != s1[i]){
		//cout << "s2[j] = s2["<<j<<"] = " << s2[j] << " vs s1[i] = s1["<<i<<"] = " << s1[i] << endl;
		ope.push_back(s1[i]);
		i--;
	    }
	    //cout << "s2[j] = s2["<<j<<"] = " << s2[j] << " vs s1[i] = s1["<<i<<"] = " << s1[i] << endl;
	    j--;
	    i--;
	}
	while(i >= 0){
	    ope.push_back(s1[i]);
	    i--;
	}
	reverse(ope.begin(), ope.end());
	
	//cout << "ope = "; for(char x : ope) cout << x << " "; cout << endl;
	
	for(char x : ope){
	    charToidx[x].pop_back();
	}

	//for(auto[k, v] : charToidx){ cout << "k = " << k << ", v = "; for(auto w : v) cout << w << " "; cout << endl;}
	
	string t = "";
	for(int i=0;i<n;i++){
	    if(charToidx[s1[i]].size() > 0){
		int idx = charToidx[s1[i]].back();
		if(i == idx){
		    t += s1[i];
		    charToidx[s1[i]].pop_back();
		}
	    }
	}

	//cout << "t = "; cout << t; cout << endl;
	
	if(t == s2){
	    cout << "YES\n";
	}else{
	    cout << "NO\n";
	}
    }

    return 0;
}

