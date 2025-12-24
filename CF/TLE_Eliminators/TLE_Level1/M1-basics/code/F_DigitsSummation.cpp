#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, m;
    cin >> n >> m;

    ll n1 = n % 10LL;
    ll m1 = m % 10LL;
	
    cout << n1+m1 << endl;

    return 0;
}

