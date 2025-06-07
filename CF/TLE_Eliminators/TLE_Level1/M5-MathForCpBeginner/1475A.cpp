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
	ll n;
	cin >> n;
	if(n <= 2){
	    cout << "NO\n";
	    continue;
	}
	while(n % 2 == 0){
	    n /= 2;
	}
	//cout << "post out two's n = " << n << '\n';
	if(n == 1){
	    cout << "NO\n";
	}else{
	    cout << "YES\n";
	}
    }
    return 0;
}

