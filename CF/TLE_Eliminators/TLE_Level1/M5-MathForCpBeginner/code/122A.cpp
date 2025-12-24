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
    int lucky[14] = {
	4, 7,
	44, 47, 74, 77,
	444, 447, 474, 744, 
	777, 477, 747, 774 
    };
    int n;
    cin >> n;
    if(n < 4){
	cout << "NO\n";
	return 0;
    }
    for(int i=0;i<14;i++){
	int l = lucky[i];
	if(n >= l && n % l == 0){
	    cout << "YES\n";
	    return 0;
	}
    }
    cout << "NO\n";
    return 0;
}

