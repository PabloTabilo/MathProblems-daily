#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    const int N = 3001;
    int dp[N];
    memset(dp, 0, sizeof(dp));
    int ans[N];
    memset(ans, 0, sizeof(ans));
    dp[1] = 1;
    for(int n = 2; n < N; n++){
	int nl = n;
	for(int i=2;i*i <= nl; i++){
	    if(nl % i == 0){
		dp[n]++;
		while(nl % i == 0){
		    nl /= i;
		}
	    }
	}
	if(nl > 1){
	    dp[n]++;
	}
    }

    for(int i=1;i<N;i++){
	ans[i] = ans[i-1];
	if(dp[i] == 2){
	    ans[i]++;
	}
    }

    int x;
    cin >> x;
    cout << ans[x] << endl;
    //cout << "dp: ";
    //for(int i=1;i<N;i++){
	//cout << dp[i] << " ";
    //}
    //cout << endl;
    return 0;
}
