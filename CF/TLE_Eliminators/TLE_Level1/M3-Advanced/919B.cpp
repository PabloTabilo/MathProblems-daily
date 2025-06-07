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
    int k;
    cin >> k;
    int BIG = 1e8 + 1;
    int ans = 0;
    for(int num=1;num<=BIG;num++){
	int s = 0;
	int myNum = num;
	while(myNum > 0){
	    s += (myNum % 10);
	    myNum /= 10;
	}
	if(s == 10){
	    k--;
	    if(k == 0){
		ans = num;
		break;
	    }
	}
    }
    cout << ans << '\n';

    return 0;
}

