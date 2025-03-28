#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int a, b;
	cin >> a >> b;
	int mn = min(a, b);
	int mx = max(a, b);
	if(a!=b && (a == 1 || b == 1)){
	    cout << 1 << endl;
	    cout << a << " " << b << endl;
	    continue;
	}
	if(mx % mn == 0){
	    cout << 2 << endl;
	    if(a == 1000000000 && b == 1000000000){
		cout << (a - 2) << " " << (b -1) << endl;
	    } 
	    else if(a == 1000000000){
		cout << (a - 2) << " " << (b + 1) << endl;
	    }else if(b == 1000000000){
		cout << (a + 2) << " " << (b - 1) << endl;
	    }
	    else{
		int xq = a + 2;
		int yq = b + 1;
		if(xq % yq == 0 || yq % xq == 0){

		}
		cout << (a + 2) << " " << (b+1) << endl;
	    }
	}else{
	    cout << 1 << endl;
	}
	cout << a << " " << b << endl;
    }

    return 0;
}

