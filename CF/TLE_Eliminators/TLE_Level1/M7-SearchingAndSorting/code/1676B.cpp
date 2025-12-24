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
	int mn = INT_MAX;
	for(int i=0;i<n;i++){
	    cin >> A[i];
	    mn = min(mn, A[i]);
	}
	int ans = 0;
	for(int i=0;i<n;i++){
	    if(A[i] > mn){
		ans += (A[i] - mn);
	    }
	}
	cout << ans << '\n';
    }
    return 0;
}

