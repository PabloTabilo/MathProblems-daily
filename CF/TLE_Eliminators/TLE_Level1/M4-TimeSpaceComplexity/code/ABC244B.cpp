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
    char * s = new char[n];
    for(int i=0;i<n;i++){
	cin >> s[i];
    }
    
    int dy = 0;
    int dx = 1;
    int y = 0;
    int x = 0;

    for(int i=0;i<n;i++){
	if(s[i] == 'S'){
	    y += dy;
	    x += dx;
	}else{
	    if(dy == 0 && dx == 1){
		dy = -1;
		dx = 0;
	    }else if(dy == -1 && dx == 0){
		dy = 0;
		dx = -1;
	    }else if(dy == 0 && dx == -1){
		dy = 1;
		dx = 0;
	    }else{
		dy = 0;
		dx = 1;
	    }
	}
    }
    cout << x << " " << y << '\n';
    return 0;
}

