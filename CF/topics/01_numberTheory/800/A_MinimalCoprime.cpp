#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int l, r;
	cin >> l >> r;
	if(l == 1 && r == 1){
	    cout << 1 << endl;
	}else{
	    cout << r - l << endl;
	}
    }

    return 0;
}

