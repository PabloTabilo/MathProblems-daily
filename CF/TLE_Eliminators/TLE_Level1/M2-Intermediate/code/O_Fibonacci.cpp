#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if(n == 1){
	cout << 0 << endl;
	return 0;
    }
    if(n == 2){
	cout << 1 << endl;
	return 0;
    }
    ll prev = 1;
    ll prevprev = 0;
    ll curr = 0;
    for(int i=3; i <= n; i++){
	curr = prev + prevprev;
	prevprev = prev;
	prev = curr;
    }
    cout << curr << endl;
    return 0;
}

