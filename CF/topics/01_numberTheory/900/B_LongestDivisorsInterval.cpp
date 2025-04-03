#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	ll n;
	cin >> n;
	ll prevL = 1;
	ll cnt = 0;
	for(ll i=1;i <= n;i++){
	    ll l = lcm(prevL, i);
	    if(n % l == 0){
		cnt++;
	    }else{
		break;
	    }
	    prevL = l;
	}
	cout << cnt << endl;
    }

    return 0;
}

