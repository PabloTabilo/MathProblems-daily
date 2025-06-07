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
    int n;
    cin >> n;
    int k = 0;
    vector<int> A;
    for(int i=0;i<n;i++){
	int v;
	cin >> v;
	if(!A.empty()){
	    int g = __gcd(A.back(), v);
	    if(g != 1){
		k++;
		A.push_back(1);
	    }
	}
	A.push_back(v);
    }
    cout << k << '\n';
    for(auto x : A){
	cout << x << " ";
    }
    cout << '\n';
    return 0;
}

