#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

void printDouble(double d){
    // fix precision, the fixed is for evit rounding 
    // rounding can be different for each compiler
    cout << fixed << setprecision(11) << d << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	ll n, x, y;
	cin >> n >> x >> y;
	ll times1 = n / x;
	ll times2 = n / y;
	if(x == y){
	    cout << 0 << '\n';
	    continue;
	}
	if(x == 1){
	    times1 -= times2;
	    ll s1 = (n * (n+1) / 2) - ((n-times1)*(n-times1+1) / 2);	
	    cout << s1 << '\n';
	    continue;
	}else if(y == 1){
	    times2 -= times1;
	    ll s2 = times2 * (times2 + 1) / 2;
	    cout << -s2 << '\n';
	    continue;
	}
	ll collisions = 0;
	/*
	for(int i = 1; x*i <= n; i++){
	    if((x*i) % y == 0){
		collisions++;
	    }
	}
	*/
	ll LCM = x * y / __gcd(x, y);
	collisions = n / LCM;
	//cout << "times1 = " << times1 << ", times2 = " << times2 << '\n'; 
	//cout << "collisions = " << collisions << '\n';
	times1 -= collisions;
	times2 -= collisions;
	//cout << "post collisions >> times1 = " << times1 << ", times2 = " << times2 << '\n'; 
	ll s1 = (n * (n+1) / 2) - ((n-times1)*(n-times1+1) / 2);	
	ll s2 = times2 * (times2 + 1) / 2;
	ll ans = s1 - s2;
	//cout << "s1 = " << s1 << ", s2 = " << s2 << '\n';
	cout << ans << '\n';

    }

    return 0;
}

