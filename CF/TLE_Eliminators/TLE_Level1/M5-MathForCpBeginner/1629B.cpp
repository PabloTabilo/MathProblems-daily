#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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
	int l, r, k;
	cin >> l >> r >> k;
	int diff = r - l + 1;
	if(k == 0){
	    if(diff == 1 && l > 1){
		cout << "YES\n";
	    }else{
		cout << "NO\n";
	    }
	    continue;
	}
	int numEven = 0;
	int numOdd = 0;
	if(l % 2 == 0){
	    if(r % 2 == 0){
		numEven = diff / 2 + 1;
	    }else{
		numEven = diff / 2;
	    }
	}else{
	    if(r % 2 == 0){
		numEven = diff / 2;
	    }else{
		numEven = diff / 2;
	    }
	}
	numOdd = diff - numEven;
	if(numOdd <= k){
	    cout << "YES\n";
	}else{
	    cout << "NO\n";
	}
    }

    return 0;
}

