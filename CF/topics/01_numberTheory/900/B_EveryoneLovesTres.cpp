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
	if(n == 1){
	    cout << -1 << endl;
	    continue;
	}
	string s = "";
	for(int i=1;i<= (n-2);i++){
	    s.push_back('3');
	}
	s += "66";
	int sumEven = 0;
	int sumOdd = 0;
	int lastIdxEven = -1;
	int lastIdxOdd = -1;
	for(int i=0;i<n;i++){
	    if(i % 2 == 0){
		sumEven += (s[i] - '0'); 
		if(i < (n-2)){
		    lastIdxEven = i;
		}
	    }else{
		sumOdd += (s[i] - '0'); 
		if(i < (n-2)){
		    lastIdxOdd = i;
		}
	    }
	}
	if((sumEven - sumOdd) == 0){
	    cout << s << endl;
	    continue;
	}
	if((sumEven - sumOdd) > 3 || lastIdxOdd == -1 || lastIdxEven == -1){
	    cout << - 1 << endl;
	    continue;
	}
	if(sumEven > sumOdd){
	    s[lastIdxOdd] = '6';
	}else if(sumEven < sumOdd){
	    s[lastIdxEven] = '6';
	}
	cout << s << endl;
    }
    return 0;
}

