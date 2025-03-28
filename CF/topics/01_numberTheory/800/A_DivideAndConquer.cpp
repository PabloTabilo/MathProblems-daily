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
	vector<int> a(n);
	int tot = 0;
	int nodd = 0;
	int mn_odd = 10000000;
	int mn_even = 10000000;
	for(int i=0;i<n;i++){
	    cin >> a[i];
	    tot += a[i];
	    if(a[i] % 2 == 1){
		nodd++;
		mn_odd = min(mn_odd, a[i]);
	    }else{
		mn_even = min(mn_even, a[i]);
	    }
	}
	if(tot % 2 == 0){
	    cout << 0 << endl;
	    continue;
	}
	int ans = 10000000;
	for(int x : a){
	    int op = 0;
	    int localSum = tot;
	    while(localSum % 2 == 1 && x > 0){
		int diff = x - (x/2);
		localSum -= diff;
		x /= 2;
		op++;
	    }
	    ans = min(ans, op);
	}
	cout << ans << endl;
    }

    return 0;
}

