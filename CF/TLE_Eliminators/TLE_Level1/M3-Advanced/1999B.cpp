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
	int A[2];
	int B[2];
	cin >> A[0] >> A[1] >> B[0] >> B[1];
	int sc = 0;
	int cnt = 0;
	for(int i=0;i<2;i++){
	    int c11 = A[i];
	    for(int j=0;j<2;j++){
		int c21 = B[j];

		if(c11 >= c21){
		    sc = 1;
		    if(c11 == c21){
			sc = 0;
		    }
		    int c12 = A[1-i];
		    int c22 = B[1-j];
		    if(c12 >= c22){
			if(c12 > c22){
			    sc++;
			}
		    }else{
			sc--;
		    }
		    if(sc > 0){
			cnt++;
		    }
		    //cout << "c11 = " << c11 << " vs c21 = " << c21 << '\n'; 
		    //cout << "c12 = " << c12 << " vs c22 = " << c22 << '\n'; 
		    //cout << "cnt = " << cnt << '\n';
		}
	    }
	}
	cout << cnt << '\n';
    }

    return 0;
}

