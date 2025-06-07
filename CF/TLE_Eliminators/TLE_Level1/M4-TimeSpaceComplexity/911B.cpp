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
static int dp[201][201][201];

void fillDp(){
    function<int(int, int, int)> fn = [&](int a, int b, int c){
	//cout << "state >> a, b, c = " << a << "," << b << "," << c << '\n';
	if(a == b && b == 0 && c > 0){
	    //cout << "position 2 is valid >> a, b, c = " << a << "," << b << "," << c << '\n';
	    //cout << "(1 << 2) = " << (1 << 2) << '\n';
	    return dp[a][b][c] = (1 << 2);
	}
	if(a == c && a == 0 && b > 0){
	    //cout << "position 1 is valid >> a, b, c = " << a << "," << b << "," << c << '\n';
	    //cout << "(1 << 1) = " << (1 << 1) << '\n';
	    return dp[a][b][c] = (1 << 1);
	}
	if(c == b && c == 0 && a > 0){
	    //cout << "position 0 is valid >> a, b, c = " << a << "," << b << "," << c << '\n';
	    //cout << "(1 << 0) = " << (1 << 0) << '\n';
	    return dp[a][b][c] = (1 << 0);
	}
	if(a < 0 || b < 0 || c < 0){
	    //cout << "lowerbound >> a, b, c = " << a << "," << b << "," << c << '\n';
	    return 0;
	}
	if(a > 200 || b > 200 || c > 200){
	    //cout << "upperbound >> a, b, c = " << a << "," << b << "," << c << '\n';
	    return 0;
	}
	if(dp[a][b][c] != -1){
	    //cout << "I SAW this >> a, b, c = " << a << "," << b << "," << c << '\n';
	    return dp[a][b][c];
	}
	int op1 = fn(a-1, b-1, c+1);
	int op2 = fn(a-1, b+1, c-1);
	int op3 = fn(a+1, b-1, c-1);
	return dp[a][b][c] = op1 | op2 | op3;
    };
    for(int i=0;i<=100;i++){
	for(int j=0;j<=100;j++){
	    for(int k=0;k<=100;k++){
		fn(i, j, k);
	    }
	}
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    fillDp();
    int t;
    cin >> t;
    while(t--){
	int a, b, c;
	cin >> a >> b >> c;
	int ans = dp[a][b][c];
	for(int bit = 0; bit < 3; bit++){
	    if(ans & (1 << bit)){
		cout << 1 << " ";
	    }else{
		cout << 0 << " ";
	    }
	}
	cout << '\n';
    }
    return 0;
}

