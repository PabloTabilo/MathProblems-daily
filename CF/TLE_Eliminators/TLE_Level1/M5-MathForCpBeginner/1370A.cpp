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
	int ans = -1;
	if(n <= 2){
	    cout << 1 << '\n';
	    continue;
	}
	if(n % 2 == 0){
	    ans = n / 2;
	    cout << ans << '\n';
	    continue;
	}
	n--;
	ans = n / 2;
	cout << ans << '\n';
    }

    return 0;
}

