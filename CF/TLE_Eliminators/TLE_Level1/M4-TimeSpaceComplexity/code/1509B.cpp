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
	string s;
	cin >> s;
	if(s[0] == 'M' || s[n-1] == 'M'){
	    cout << "NO" << endl;
	    continue;
	}
	bool isPossible = true;
	queue<int> qt;
	int prefixCnt = 0;
	int cntM = 0;
	int cntT = 0;
	for(int i=0;i<n && isPossible;i++){
	    if(s[i] == 'T'){
		qt.push(i);
		cntT++;
	    }else{
		if(qt.empty()){
		    isPossible = false;
		    break;
		}
		prefixCnt++;
		qt.pop();
		cntM++;
	    }
	}
	if(cntT != 2*cntM){
	    cout << "NO" << endl;
	    continue;
	}
	queue<int> qtSuffix;
	for(int i=n-1;i>=0 && isPossible;i--){
	    if(s[i] == 'T'){
		qtSuffix.push(i);
	    }else{
		if(qtSuffix.empty()){
		    isPossible = false;
		    break;
		}
		qtSuffix.pop();
	    }
	}
	if(isPossible){
	    if(prefixCnt > 0 && prefixCnt == qt.size()){
		cout << "YES" << endl;
		continue;
	    }
	}
	cout << "NO" << endl;
	}
    return 0;
}

