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
    int * A = new int[n];
    for(int i=0;i<n;i++){
	cin >> A[i];
    }
    int l = 0;
    int r = 1;
    int left, right;
    while(r < n){
	//cout << "l, r = " << l << ", " << r << '\n';
	left = A[l];
	right = A[r];
	//cout << "left, right = " << left << ", " << right << '\n';
	if(abs(left - right) > 1){
	    if(left < right){
		for(int k = left; k < right; k++){
		    cout << k << " ";
		}
	    }else{
		for(int k = left; k > right; k--){
		    cout << k << " ";
		}
	    }
	}else{
	    cout << left << " ";
	}
	l++;
	r++;
    }
    cout << right << " ";

    return 0;
}

