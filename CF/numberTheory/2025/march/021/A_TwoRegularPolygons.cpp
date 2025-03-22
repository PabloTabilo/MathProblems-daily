#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
	int m, n;
	cin >> m >> n;
	int mn = min(m, n);
	int mx = max(m, n);
	if(mx % mn == 0){
	    cout << "YES" << endl;
	}else{
	    cout << "NO" << endl;
	}
    }
    return 0;
}

