#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

void sieve(map<int, set<int>> & p){
    const int MX = 2e5 + 1;
    vector<bool> dp(MX, true);
    dp[0] = dp[1] = false;
    vector<int> primes;
    for(int i=2;i*i <= MX; i++){
	if(dp[i]){
	    dp[i] = true;
	    primes.push_back(i);
	    for(int j=2;i*j <= MX; j++){
		dp[j*i] = false;
		p[i].insert(j*i);
	    }
	}
    }
    int m = primes.size();
    for(int i=0;i<m;i++){
	int pi = primes[i];
	for(int j=0;j<m;j++){
	    int qi = primes[j];
	    if(pi != qi) p[pi].insert(qi);
	    p[pi*qi].insert(pi*qi);
	    p[pi*qi].insert(pi);
	    p[pi*qi].insert(qi);
	}
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    map<int, set<int>> p;
    sieve(p);
    int t;
    cin >> t;
    while(t--){
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> f;
	int mx = 0;
	for(int i=0;i < n; i++){
	    cin >> a[i];
	    mx = max(mx, a[i]);
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
	    int x = a[i];
	    f[x]++;
	    int local_cnt = 0;
	    for(int semi : p[x]){
		if(semi > mx){
		    break;
		}
		//cout << "x = "<< x <<", semi = " << semi << endl;
		if(f.count(semi) > 0){
		    local_cnt += f[semi];
		}
		//cout << "local_cnt = " << local_cnt << endl;
	    }
	    cnt += local_cnt;
	    //cout << "cnt = " << cnt << endl;
	    //cout << "-------------------" << endl;
	}	
	//cout << "cnt = ";
	cout << cnt << endl;
    }
    return 0;
}

