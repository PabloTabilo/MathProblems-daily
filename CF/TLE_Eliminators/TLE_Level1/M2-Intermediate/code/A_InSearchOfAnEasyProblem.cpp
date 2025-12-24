#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cin.get();
    
    char c;
    string ans = "EASY";
    while(cin.get(c) && c != '\n'){
	if(c == ' ') continue;
	if(c == '1'){
	    ans = "HARD";
	}	
    }
    cout << ans << endl;
    return 0;
}

