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
	int numEven = 0;
	int numOdds = 0;
	int minEven = INT_MAX;
	for(int i=0;i<n;i++){
	    cin >> A[i];
	    if(A[i] % 2 == 0){
		numEven++;
		minEven = min(minEven, A[i]);
	    }else{
		numOdds++;
	    }
	}
	//cout << "numEven = " << numEven << ", numOdds = " << numOdds << '\n';
	int ope = INT_MAX;
	if(numEven == 0 && numOdds > 0){
	    if(numOdds % 2 == 0){
		cout << 0;
	    }else{
		for(int i=0;i<n;i++){
		    if(A[i] % 2 == 1){
			int c = A[i];
			int localOpe = 0;
			while(c % 2 == 1){
			    c /= 2;
			    localOpe++;
			}
			ope = min(ope, localOpe);
		    }
		}
		cout << ope;
	    }
	}else if(numOdds == 0 && numEven > 0){
	    cout << 0;
	}else{
	    if(numOdds % 2 == 0){
		cout << 0;
	    }else{
		for(int i=0;i<n;i++){
		    if(A[i] % 2 == 1){
			int c = A[i];
			int localOpe = 0;
			while(c % 2 == 1){
			    c /= 2;
			    localOpe++;
			}
			ope = min(ope, localOpe);
		    }else{
			int c = A[i];
			int localOpe = 0;
			while(c % 2 == 0){
			    c /= 2;
			    localOpe++;
			}
			ope = min(ope, localOpe);
		    }
		}
		cout << ope;
	    }
	}
	cout << '\n';
    }
    return 0;
}

