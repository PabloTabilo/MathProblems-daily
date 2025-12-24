#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    set<int> s;
    for(int i=1;i*i <= n; i++){
	if(n % i == 0){
	    s.insert(i);
	    int j = n / i;
	    if(n % j == 0 && i != j){
		s.insert(j);
	    }
	}
    }
    for(auto v : s){
	cout << v << endl;
    }
    return 0;
}

