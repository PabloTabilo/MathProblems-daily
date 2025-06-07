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
    vector<int> A(n);
    for(int i=0;i<n;i++){
	cin >> A[i];
    }

    function<bool(int)> dfs = [&](int i){
	if(B[i] == 0){
	    while(B[i] >= B[i+1]){

	    }
	    B[i] += A[i];
	}
	if(B[i] >= B[i+1])
    };

    return 0;
}

