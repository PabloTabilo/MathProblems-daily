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
    getline(cin, s);
    string t;
    int n = s.length();
    function<bool(char)> isChar = [](char c){
	int v = int(c);
	return v >= 97 && v <= 122;
    };
    //cout << "n = " << n << endl;
    for(int i=0;i<n;i++){
	// always start with a letter
	// never t is empty
	//cout << "t = " << t << endl;
	//if(!t.empty()) cout << "t.back() = " << t.back() << endl;
	//cout << "s[i] = s["<<i<<"] = " << s[i] << endl;
	if(isChar(s[i])){
	    t.push_back(s[i]);
	}
	else if(s[i] == ' ' && isChar(t.back()) ){
	    //cout << "pre while i = " << i << endl;
	    while(i < n &&s[i] == ' '){
		i++;
	    }
	    //cout << "post while i = " << i << endl;
	    // The text begin and end with a Lattin letter
	    // case: a b...
	    if(isChar(s[i])){
		t.push_back(' ');
		t.push_back(s[i]);
	    }
	    // case: a, ...
	    else{
		t.push_back(s[i]);
		t.push_back(' ');
	    }   
	}
	// is a punctuation mark
	else if(s[i] != ' ' && !isChar(s[i]) ){
	    t.push_back(s[i]);
	    i++;
	    while(i < n && s[i] == ' ' || !isChar(s[i]) ){
		if(!isChar(s[i]) && s[i] != ' '){
		    t.push_back(s[i]);
		}
		i++;
	    }
	    if(i < n){
		t.push_back(' ');
		t.push_back(s[i]);
	    }
	}
    }
    cout << t << '\n';
    return 0;
}

