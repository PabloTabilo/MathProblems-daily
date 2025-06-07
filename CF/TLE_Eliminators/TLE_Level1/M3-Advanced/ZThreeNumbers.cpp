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
    int K, S;
    cin >> K >> S;
    int cnt = 0;
    // O(k * k)
    for(int x = 0; x <= K; x++){
	if(x > S){
	    break;
	}
	for(int y=0;y<=K;y++){
	    if(y > S){
		break;
	    }
	    int z = S - x - y;
	    if(z >= 0 && z <= K){
		cnt++;
	    }
	}
    }
    cout << cnt << "\n";
    return 0;
}

