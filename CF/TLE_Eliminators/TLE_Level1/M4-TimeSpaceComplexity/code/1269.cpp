#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    // a - b = n = 3*n - 2*n
    
    if(n == 1){
	cout << 9 << " " << 8 << endl;
	return 0;
    }

    cout << 3*n << " " << 2*n << endl;

    return 0;
}

