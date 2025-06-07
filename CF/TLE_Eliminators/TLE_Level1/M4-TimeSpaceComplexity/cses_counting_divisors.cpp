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
    int n, x;
    cin >> n;
    while(n--){
	cin >> x;
	int cnt = 0;
	for(int i=1; i*i <= x; i++){
	    if(x % i == 0){
		int c = x / i;
		cnt++;
		if(x % c == 0 && i != c){
		    cnt++;
		}
	    }
	}	
	cout << cnt << '\n';
    }

    return 0;
}

