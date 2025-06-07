#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int n, m;
	cin >> n >> m;
	bool isSymmetric = false;
	int tl, tr, bl, br;
	for(int i=0;i<n;i++){
	    cin >> tl >> tr;
	    cin >> bl >> br;
	    //cout << "tl = " << tl << ", tr = " << tr << endl;
	    //cout << "bl = " << bl << ", br = " << br << endl;
	    //cout << "tl == br ? : " << (tl == br) << endl;
	    //cout << "bl == tr ? : " << (bl == tr) << endl;
	    if( (bl == tr)){
		isSymmetric = true;
	    }
	}
	//cout << "isSymmetric = " << isSymmetric << endl;
	if((m % 2 != 0) || (!isSymmetric)){
	    cout << "NO" << endl;
	}else{
	    cout << "YES" << endl;
	}
    }
    return 0;
}

