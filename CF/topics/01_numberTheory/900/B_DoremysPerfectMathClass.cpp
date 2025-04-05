#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int n;
	cin >> n;
	int g = 0;
	int a;
	int mx = -1;
	for(int i=0;i<n;i++){
	    cin >> a;
	    g = gcd(g, a);
	    mx = max(mx, a);
	}
	if(g == 1){
	    cout << mx << endl;
	}else{
	    cout << mx / g << endl;
	}

    }
    return 0;
}

