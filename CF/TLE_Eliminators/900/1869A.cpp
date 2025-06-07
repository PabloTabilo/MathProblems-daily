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
	int n;
	cin >> n;
	int * A = new int[n];
	int xorAcc = -1;
	bool existOneNonZero = false;
	for(int i=0;i<n;i++){
	    cin >> A[i];
	    if(A[i] != 0){
		existOneNonZero = true;
	    }
	    if(xorAcc == -1){
		xorAcc = A[i];
	    }else{
		xorAcc ^= A[i];
	    }
	}
	if(!existOneNonZero){
	    cout << 0 << '\n';
	}else{
	    if(xorAcc == 0){
		cout << 1 << '\n';
		cout << 1 << " " << n << '\n';
	    }else{
		cout << 2 << '\n';
		cout << 1 << " " << n << '\n';
		cout << 1 << " " << n << '\n';
	    }
	}
    }

    return 0;
}

