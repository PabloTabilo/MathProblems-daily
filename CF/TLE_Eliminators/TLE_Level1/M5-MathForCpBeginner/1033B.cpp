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
	ll a1, a2;
	cin >> a1 >> a2;
	//cout << "a1, a2 = " << a1 << ", " << a2 << '\n';
	if(a1 < a2){
	    swap(a1, a2);
	}
	//cout << "POST SWAP a1, a2 = " << a1 << ", " << a2 << '\n';
	ll A = a1 + a2;
	ll B = a1 - a2;
	//cout << "A = " << A << ", B = " << B << '\n';
	if(B == 1){
	    ll prevA = A;
	    for(ll i=2;i*i <= A; i++){
		while(A >= i && A % i == 0){
		    A /= i;
		}
	    }
	    //cout << "post A = " << A << " vs prevA = " << prevA << '\n'; 
	    // is prime
	    if(A == prevA){
		cout << "YES\n";
	    }else{
		cout << "NO\n";
	    }
	}else{
	    cout << "NO\n";
	}
    }

    return 0;
}

