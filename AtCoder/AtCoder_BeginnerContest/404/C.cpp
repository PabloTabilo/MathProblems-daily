#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int u, v;
    vector<int> degree(n+1, 0);
    unordered_map<int, vector<int>> adj;
    for(int i=0;i<m;i++){
	cin >> u >> v;
	degree[u]++;
	degree[v]++;
	adj[u].push_back(v);
	adj[v].push_back(u);
    }
    // if all are 2 so must exists a cycle
    bool isPossible = true;
    for(int i=1;i<=n;i++){
	if(degree[i] != 2){
	    isPossible = false;
	    break;
	}
    }

    if(!isPossible){
	cout << "No" << endl;
	return 0;
    }
    
    queue<int> q;
    q.push(1);
    vector<bool> vis(n+1, false);
    int cnt = 0;
    while(!q.empty()){
	int u1 = q.front();
	q.pop();
	if(vis[u1]){
	    continue;
	}
	cnt++;
	//cout << "u1 = " << u1 << endl;
	//cout << "cnt = " << cnt << endl;
	vis[u1] = true;
	for(auto v1 : adj[u1]){
	    if(vis[v1]){
		continue;
	    }
	    q.push(v1);
	}
    }
    //cout << "Final cnt = " << cnt << endl;
    if(cnt != n){
	cout << "No" << endl;
    }else{
	cout << "Yes" << endl;
    }

    return 0;
}

