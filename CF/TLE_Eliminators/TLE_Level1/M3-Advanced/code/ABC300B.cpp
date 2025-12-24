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
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    int H, W;
    cin >> H >> W;
    char ** A = new char*[H];
    char ** B = new char*[H];
    for(int i=0;i<H;i++){
	A[i] = new char[W];
	B[i] = new char[W];
    }
    for(int i=0;i<H;i++){
	for(int j=0;j<W;j++){
	    cin >> A[i][j];
	}
    }

    
    for(int i=0;i<H;i++){
	for(int j=0;j<W;j++){
	    cin >> B[i][j];
	}
    }

    auto checkMe = [&](int h, int w){
	for(int i=0;i<H;i++){
	    for(int j=0;j<W;j++){
		char c = A[(i +  h) % H][(j + w) % W];
		if(c != B[i][j]){
		    return false;
		}
	    }
	}
	return true;
    };
    for(int h = 0; h < H; h++){
	for(int w = 0; w < W;  w++){
	    if(checkMe(h, w)){
		cout << "Yes\n";
		return 0;
	    }
	}
    }
    cout << "No\n";
    return 0;
}

