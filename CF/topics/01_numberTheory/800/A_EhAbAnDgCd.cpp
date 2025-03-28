#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int x;
	cin >> x;
	// gcd(a,b) + lcm(a,b) = x
	cout << 1 << " " << x-1 << endl;
    }
    return 0;
}

