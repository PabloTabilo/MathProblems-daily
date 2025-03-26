#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	ll n, m, k;
	cin >> n >> m >> k;
	if(n * m == k){
	    cout << m << endl;
	}else{
	    cout << "n, m, k = " << n << "," << m << "," << k << endl;
	    int e1 = m / 2;
	    e1 += m%2 == 1;
	    k -= e1*n;
	    int sz = 1;
	    int len = 1;
	    cout << "e1 = "<< e1 << ", k = " << k << ", sz = " << sz << endl;
	    while(k > 0){
		int t = k/n;
		if(t == 0){
		    sz += 1;
		    len += 2;
		    break;
		}
		k -= n*t;
		sz += t;
		len += 2;
	    }
	    cout << "len = " << len << endl;
	    cout << sz << endl;
	}
    }

    return 0;
}

