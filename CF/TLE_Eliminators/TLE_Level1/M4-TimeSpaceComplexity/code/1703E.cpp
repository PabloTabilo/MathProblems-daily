#include <iostream>
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
	vector<vector<int>> o(n, vector<int>(n, 0));
	string s;
	for(int i=0;i<n;i++){
	    cin >> s;
	    for(int j=0;j<n;j++){
		o[i][j] = s[j]-'0';
	    }
	}
	vector<vector<bool>> vis(n, vector<bool>(n, false));
	ll ans = 0;
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
		//cout << "i, j = " << i << ", " << j << endl;
		if(vis[i][j]){
		    continue;
		}
		if(n % 2 != 0 && i == (n/2) && j == (n/2)){
		    continue;
		}
		ll c1 = 0;
		ll c0 = 0;
		//cout << "CHECK ORIENTATIONS"<<endl;
		
		// 0d
		//cout << "i, j = " << i << ", " << j << endl;
		if(!vis[i][j] && o[i][j] == 1){
		    c0++;
		}else{
		    c1++;
		}
		vis[i][j] = true;
		
		// 90d
		//cout << "j, n-1-i = " << j << ", " << n-1-i << endl;
		if(!vis[j][n-1-i] && o[j][n-1-i] == 1){
		    c0++;
		}else{
		    c1++;
		}
		vis[j][n-1-i] = true;
		
		// 180d
		//cout << "n-1-i, n-1-j = " << n-1-i << ", " << n-1-j << endl;
		if(!vis[n-1-i][n-1-j] && o[n-1-i][n-1-j] == 1){
		    c0++;
		}else{
		    c1++;
		}
		vis[n-1-i][n-1-j] = true;
		
		// 270d
		//cout << "n-1-j, i = " << n-1-j << ", " << i << endl;
		if(!vis[n-1-j][i] && o[n-1-j][i] == 1){
		    c0++;
		}else{
		    c1++;
		}
		vis[n-1-j][i] = true;
		//cout << "c0 = " << c0 << " vs c1 = " << c1 << endl;
		ll mn = min(c0, c1);
		ans += mn;
		//cout << "----------------------" << endl;
	    }
	}
	cout << ans << '\n';
    }
    return 0;
}

