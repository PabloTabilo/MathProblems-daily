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
	int a, b;
	cin >> a >> b;
	if(a % b == 0){
	    cout << 0 << '\n';
	    continue;
	}
	int times = a / b;
	int reachMe = b * (times + 1);
	int diff = reachMe - a;
	cout << diff << '\n';
    }

    return 0;
}

