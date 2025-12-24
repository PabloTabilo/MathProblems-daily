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
	int xorA = 0;
	for(int i=0;i<n;i++){
	    cin >> A[i];
	    xorA ^= A[i];
	}
	if(xorA > 0){
	    if(n%2 == 0){
		cout << 2 << '\n';
		cout << 1 << " " << n << '\n';
		cout << 1 << " " << n << '\n';
	    }else{
		cout << 4 << '\n';
		cout << 1 << " " << n << '\n';
		cout << 1 << " " << n-1 << '\n';
		cout << n-1 << " " << n << '\n';
		cout << n-1 << " " << n << '\n';
	    }
	}else{
	    cout << 1 << '\n';
	    cout << 1 << " " << n << '\n';
	}
    }
    return 0;
}

