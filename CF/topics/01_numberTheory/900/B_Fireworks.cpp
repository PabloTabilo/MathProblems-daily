#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	ll a, b, m;
	cin >> a >> b >> m;
	//ll l = lcm(a, b);

	ll contribution_a = m/a + 1;
	ll contribution_b = m/b + 1;

	ll ans = contribution_a + contribution_b;
	cout << ans << endl;
    }

    return 0;
}

