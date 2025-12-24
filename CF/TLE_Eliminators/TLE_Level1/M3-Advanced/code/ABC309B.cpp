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
    int ** A = new int*[n];
    for(int i=0;i<n;i++){
	A[i] = new int[n];
    }

    int * fr = new int[n]; // only read first row
    int * lr = new int[n]; // only read last row
    int * fc = new int[n]; // only read first col
    int * lc = new int[n]; // only read last col
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    char c;
	    cin >> c;
	    int v = c - '0';
	    A[i][j] = v;
	    if(i == 0){
		fr[j] = v;
	    }else if(i == (n-1)){
		lr[j] = v;
	    }
	    if(j == 0){
		fc[i] = v;
	    }else if(j == (n-1)){
		lc[i] = v;
	    }
	}
    }
    function<void(int*, bool)> shiftMe = [&n](int * data, bool forward){
	if(forward){
	    for(int i=n-1;i>=1;i--){
		data[i] = data[i-1];
	    }
	    data[0] = 0;
	}else{
	    for(int i=0;i<n-1;i++){
		data[i] = data[i+1];
	    }
	    data[n-1] = 0;
	}
    };

    //cout << "fr: "; for(int i=0;i<n;i++) cout << fr[i] << " "; cout << '\n';
    shiftMe(fr, true);
    shiftMe(lc, true);
    shiftMe(lr, false);
    shiftMe(fc, false);
    /*
    cout << "shift >> fr: "; for(int i=0;i<n;i++) cout << fr[i]; cout << '\n';
    cout << "shift >> lc: "; for(int i=0;i<n;i++) cout << lc[i]; cout << '\n';
    cout << "shift >> lr: "; for(int i=0;i<n;i++) cout << lr[i]; cout << '\n';
    cout << "shift >> fc: "; for(int i=0;i<n;i++) cout << fc[i]; cout << '\n';
    */
    for(int j=1;j<n;j++){
	A[0][j] = fr[j];
    }
    for(int i=1;i<n;i++){
	A[i][n-1] = lc[i];
    }
    for(int j=n-2;j>=0;j--){
	A[n-1][j] = lr[j];
    }
    for(int i=n-2;i>=0;i--){
	A[i][0] = fc[i];
    }
    //cout << "new matrix: \n";
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    cout << A[i][j];
	}
	cout << '\n';
    }
    cout << '\n';
    return 0;
}

