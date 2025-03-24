#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

const int N = 1e5 + 1;

vector<bool> sieve(){
    vector<bool> dp(N, true);
    dp[0] = dp[1] = false;
    for(int i=2;i*i < N; i++){
	if(dp[i]){
	    for(int j=2;j*i < N; j++){
		dp[i*j] = false;
	    }
	}
    }
    return dp;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int n;
	cin >> n;
	vector<int> p(n+1, 0);
	for(int i=1; i<=n;i++) p[i] = i;
	for(int i = n; i>= 1; i-=2){
	    if((i-1) >= 1){
		swap(p[i], p[i-1]);
	    }
	}
	//cout << "p: ";
	for(int i=1; i<=n;i++){
	    cout << p[i] << " ";
	}
	cout << endl;
    }

    return 0;
}

