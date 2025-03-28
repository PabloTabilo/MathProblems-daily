#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int a, b;
	cin >> a >> b;
	cout << lcm(a, b) << endl;
    }
    return 0;
}

