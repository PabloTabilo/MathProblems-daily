#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int y;
    cin >> y;
    bool someDigitsRepeat = true;
    int i = y + 1;
    for(; someDigitsRepeat; i++){
	int num = i;
	vector<int> digits(10, 0);
	someDigitsRepeat = false;
	while( num > 0 ){
	    int d = num % 10;
	    digits[d]++;
	    num /= 10;
	}
	for(auto c : digits){
	    if(c > 1){
		someDigitsRepeat = true;
	    }
	}
    }
    cout << (i-1) << endl;
    return 0;
}

