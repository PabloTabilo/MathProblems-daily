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
	int n;
	cin >> n;
	int a;
	int cntIncorrectEven = 0;
	int cntIncorrectOdds = 0;
	for(int i=0;i<n;i++){
	    cin >> a;
	    if((i % 2 == 0) && (a % 2 != 0)){
		cntIncorrectEven++;
	    }
	    if((i % 2 != 0) && (a % 2 == 0)){
		cntIncorrectOdds++;
	    }
	}
	//cout << "cntIncorrectOdds = " << cntIncorrectOdds << endl;
	//cout << "cntIncorrectEven = " << cntIncorrectEven << endl;
	if(cntIncorrectEven != cntIncorrectOdds){
	    cout << -1 << endl;
	    continue;
	}
	cout << cntIncorrectEven << endl;
    }

    return 0;
}

