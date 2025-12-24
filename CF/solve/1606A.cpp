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
	int n = s.size();
	vector<int> AB(n, 0);
	int cntAB = 0;
	vector<int> BA(n, 0);
	int cntBA = 0;
	for(int i=0;i<n;i++){
	    if((i+1)<n){
		string t = "";
		t+=s[i];
		t+=s[i+1];
		if(t == "ab"){
		    AB[i] = 1;
		    cntAB++;
		}
		if(t == "ba"){
		    BA[i] = 1;
		    cntBA++;
		}
	    }
	}
	if(cntAB == cntBA){
	    cout << s;
	    //cout << endl;
	    cout << '\n';
	    continue;
	}

	//cout << "AB: "; for(int x : AB) cout << x << " "; cout << endl;
	//cout << "BA: "; for(int x : BA) cout << x << " "; cout << endl;
	

	for(int i=0;i<n;i++){
	    int localAB = cntAB;
	    int localBA = cntBA;
	    char curr = s[i];
	    if((i-1)>=0){
		string t = "";
		t+=s[i-1];
		if(s[i] == 'a'){
		    t+='b';
		}else{
		    t+='a';
		}
		if(t == "ab"){
		    localAB++;
		    if(BA[i-1] == 1){
			localBA--;
		    }    
		}
		else if(t == "ba"){
		    localBA++;
		    if(AB[i-1] == 1){
			localAB--;
		    }    
		}else{
		    if(AB[i] == 1){
			localAB--;
		    }
		    if(BA[i] == 1){
			localBA--;
		    }
		}
	    }
	    if((i+1)<n){
		string t = "";
		if(s[i] == 'a'){
		    t+='b';
		}else{
		    t+='a';
		}
		t+=s[i+1];
		if(t == "ab"){
		    localAB++;
		    if(BA[i] == 1){
			localBA--;
		    }    
		}
		else if(t == "ba"){
		    localBA++;
		    if(AB[i] == 1){
			localAB--;
		    }    
		}else{
		    if(AB[i] == 1){
			localAB--;
		    }
		    if(BA[i] == 1){
			localBA--;
		    }
		}

	    }
	    //cout << "i = "<<i<<", localAB = " << localAB << " vs localBA = " << localBA << endl;
	    if(localAB == localBA){
		if(curr == 'a'){
		    s[i] = 'b';
		}else{
		    s[i] = 'a';
		}
		break;
	    }
	}
	//cout << "new s = ";
	cout << s;
	cout << '\n';
	//cout << endl;
    }

    return 0;
}

