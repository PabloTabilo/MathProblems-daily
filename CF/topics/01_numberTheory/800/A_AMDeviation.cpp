#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int a1, a2, a3;
	cin >> a1 >> a2 >> a3;
	int tot = a1 + a3;
	int ans = abs(tot - 2*a2);
	while(ans > 1){
	    int x = tot / 2;
	    int diff = x - a2;
	    if(a2 == x){
		break;
	    }
	    tot += -1*diff;
	    a2 = x;
	    ans = min(ans, abs(tot-2*a2));
	}
	//cout << "ans = ";
	cout << ans << endl;
    }

    return 0;
}

