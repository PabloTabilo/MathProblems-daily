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
	function<bool(int)> isPerfectSquare = [](int x){
	    if(x == 1){
		return true;
	    }
	    int ap = 0;
	    for(int i=2;i*i <= x; i++){
		ap = i*i;
	    }
	    return ap == x;
	};
	bool possible = true;
	for(int i=0;i<n;i++){
	    int x;
	    cin >> x;
	    if(!isPerfectSquare(x)){
		possible = false;
	    }
	}
	if(!possible){
	    cout << "YES" << endl;
	}else{
	    cout << "NO" << endl;
	}
    }

    return 0;
}

