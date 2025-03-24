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
	int cnt = 0; // cnt ones
	int a;
	for(int i=0;i<2*n;i++){
	    cin >> a;
	    if(a == 1){
		cnt++;
	    }
	}
	int mx = min(cnt, 2*n - cnt); // max number of lights
	int mn;
	if(cnt % 2 == 0){
	    mn = 0;
	}else{
	    if((2*n-cnt) % 2 == 0){
		mn = 0;
	    }else{
		mn = 1;
	    }
	}
	cout << mn << " " << mx << endl;
    }

    return 0;
}

