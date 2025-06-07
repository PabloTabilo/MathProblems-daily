#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll>cost(n+1, 0);
    for(int i=1;i<=n;i++){
	cin >> cost[i];
    }
    unordered_map<int, vector<int>> animals;
    unordered_map<int, vector<int>> zoo;
    for(int i=1;i<=m;i++){
	int sz, zooIdx;
	cin >> sz;
	for(int j=0;j<sz;j++){
	    cin >> zooIdx;
	    animals[i].push_back(zooIdx);
	    zoo[zooIdx].push_back(i);
	}
    }
    vector<int>cnt(m+1,0);
    ll INF = 10000000;
    function<ll(int)> dfs = [&](int i) -> ll{
	bool continueRecursion = false;
	for(int idx=1;idx<=m;idx++){
	    if(cnt[idx] < 2){
		continueRecursion = true;
		break;
	    }
	}
	if(!continueRecursion){
	    return 0LL;
	}
	ll tot = INF;
	for(auto zooIdx : animals[i]){
	    ll curr_cost = cost[zooIdx];
	    for(auto animalsIdx : zoo[zooIdx]){
		cnt[animalsIdx]++;
	    }

	    // this animals was saw more than 2 times
	    for(int idx = 1;idx<=m;idx++){
		if(cnt[idx] < 2){
		    ll remain = dfs(idx);
		    tot = min(tot, remain + curr_cost);
		}
	    }
	    
	    for(auto animalsIdx : zoo[zooIdx]){
		cnt[animalsIdx]--;
	    }
	}
	return tot;
    };

    ll ans = dfs(1);
    cout << "ans = ";
    cout << ans << endl;

    return 0;
}

