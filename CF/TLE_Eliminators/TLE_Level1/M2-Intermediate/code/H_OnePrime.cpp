#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x;
    cin >> x;
    // x >= 2
    if(x > 2 && x % 2 == 0){
	cout << "NO" << endl;
	return 0;
    }

    for(int i=3;i*i <= x;i++){
	if(x % i == 0){
	    cout << "NO" << endl;
	    return 0;
	}
    }
    
    cout << "YES" << endl;

    return 0;
}

