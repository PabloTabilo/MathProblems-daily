#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    int v;
    int cntE = 0;
    int cntO = 0;
    int cntPos = 0;
    int cntNeg = 0;
    for(int i=0;i<N;i++){
	cin >> v;
	if(v % 2 == 0){
	    cntE++;
	}else{
	    cntO++;
	}
	if(v > 0){
	    cntPos++;
	}else if(v < 0){
	    cntNeg++;
	}
    }

    cout << "Even: " << cntE << endl;
    cout << "Odd: " << cntO << endl;
    cout << "Positive: " << cntPos << endl;
    cout << "Negative: " << cntNeg << endl;

    return 0;
}

