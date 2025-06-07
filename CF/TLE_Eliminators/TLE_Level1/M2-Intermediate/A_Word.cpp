#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int cntLower = 0;
    int cntUpper = 0;
    for(auto c : s){
	int v = int(c);
	if(v >= 97){
	    cntLower++;
	}else{
	    cntUpper++;
	}
    }
    if(cntLower >= cntUpper){
	transform(s.begin(), s.end(), s.begin(), ::tolower);
    }else{
	transform(s.begin(), s.end(), s.begin(), ::toupper);
    }

    cout << s << endl;

    return 0;
}

