#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, t;
    cin >> n >> t;
    string q;
    cin >> q;
    while(t--){
	vector<int> swapMe;
	for(int i=0;i<n;i++){
	    if((i-1) >= 0 && q[i] == 'G' && q[i-1] == 'B'){
		swapMe.push_back(i);
	    }
	}
	for(auto idx : swapMe){
	    swap(q[idx-1], q[idx]);
	}
    }

    cout << q << endl;

    return 0;
}

