#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	// 5 3 3 
	// 1 1 7
	// 3
	// 2 (+1)
	// 1 -> min(1+1,5) (+1)
	// 2 
	// 1 -> min(1+1,5) (+1)
	// 2
	// 1 -> min(1+7,5) (+1)
	// 5
	// 4 (+1)
	// 3 (+1)
	// 2 (+1)
	// 1 (+1)
	// 0 (+1)
	// res : 9
	
	ll a, b, n;
	cin >> a >> b >> n;
	vector<ll> x(n);
	for(int i=0;i<n;i++){
	    cin >> x[i];
	}
	//sort(x.begin(), x.end());
	ll seconds = 0;
	for(int i=0;i<n;i++){
	    //cout << "pre b = " << b << endl;
	    seconds += (b-1);
	    b = min(x[i] + 1LL, a);
	    //cout << "seconds = " << seconds << endl;
	    //cout << "post b = " << b << endl;
	}
	seconds += b;
	cout << seconds << endl;
    }
    return 0;
}

