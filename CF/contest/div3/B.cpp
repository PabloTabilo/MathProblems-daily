#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i=0;i <n;i++){
	    cin >> a[i];
	}
	sort(a.begin(), a.end());
	int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
	int ans = n - idx;
	for(int i=idx-1;i>=0;i--){
	    int c = a[i];
	    int idx0 = lower_bound(a.begin(), a.end(), c) - a.begin();
	    int sz = idx - idx0;
	    //cout << "c = " << c << ", sz = " << sz << endl;
	    if(c*sz >= x){
		ans++;
		idx = idx0;
	    }
	}
	cout << ans << endl;
    }

    return 0;
}

