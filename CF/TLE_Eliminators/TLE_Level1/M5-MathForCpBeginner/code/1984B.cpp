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
    int t;
    cin >> t;
    while(t--){
	string s;
	cin >> s;
	int n = s.length();
	if(s[0] != '1' || s[n-1] > '8'){
	    cout << "NO\n";
	    continue;
	}
	bool isPossible = true;
	for(int i=1;i<(n-1);i++){
	    if(s[i] == '0'){
		isPossible = false;
		break;
	    }
	}
	if(!isPossible) cout << "NO\n";
	else cout << "YES\n";
    }

    return 0;
}

