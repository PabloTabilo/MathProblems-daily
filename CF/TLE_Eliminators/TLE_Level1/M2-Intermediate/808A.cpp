#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if(n < 10){
	cout << 1 << endl;
	return 0;
    }
    string sn = to_string(n);
    int numDigits = sn.length();
    int head_d = int(sn[0] - '0') + 1;
    for(int i=0;i<numDigits-1;i++){
	head_d *= 10;
    }
    //cout << "head_d: ";
    //cout << head_d << endl;
    int diff = head_d - n;
    //cout << "diff: ";
    cout << diff << endl;
    return 0;
}

