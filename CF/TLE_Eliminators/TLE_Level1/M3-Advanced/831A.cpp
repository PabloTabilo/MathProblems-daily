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
    bool isPossible = true;
    bool existIncre = false;
    bool existDecre = false;
    bool existConstant = false;
    for(int i=0;i<(n-1);i++){
	if(A[i] < A[i+1]){
	    if(existConstant || existDecre){
		isPossible = false;
		break;
	    }
	    existIncre = true;
	}else if(A[i] == A[i+1]){
	    if(existDecre){
		isPossible = false;
		break;
	    }
	    existConstant = true;
	}else{
	    existDecre = true;
	}
    }
    if(isPossible){
	cout << "YES\n";
    }else{
	cout << "NO\n";
    }

    return 0;
}

