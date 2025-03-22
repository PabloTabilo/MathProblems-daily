#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int N = 2e5 + 1;

vector<int> sieve(){
    bool dp[N];
    memset(dp, true, N*sizeof(dp[0]));
    dp[0] = dp[1] = false;
    vector<int> p; // primes numbers are lower
    for(int i=2; i*i <= N; i++){
	if(dp[i]){
	    p.push_back(i);
	    for(int j=2; j*i <= N; j++){
		dp[i*j] = false;
	    }
	}
    }
    vector<int> nearlyPrimes;
    int m = p.size();
    for(int i = 0; i < m; i++){
	for(int j = i + 1; j < m; j++){
	    nearlyPrimes.push_back(p[i] * p[j]);
	}
    }
    sort(nearlyPrimes.begin(), nearlyPrimes.end());
    return nearlyPrimes;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> np = sieve();
    int t;
    cin >> t;
    while(t--){
	int n;
	cin >> n;
	int n_copy = n;
	int m = np.size();
	int x, y, w;
	bool found = false;
	//cout << "np: "; for(auto x : np) cout << x << " "; cout << endl;
	for(int i = 0; i < m && !found; i++){
	    if(n_copy <= np[i]){
		break;
	    }
	    n_copy -= np[i];
	    if(!found) x = np[i];
	    //cout << "n_copy = " << n_copy << ", x = " << x << endl;
	    for(int j=0;j<m && !found;j++){
		if(i == j){
		    continue;
		}
		if(n_copy <= np[j]){
		    break;
		}
		n_copy -= np[j];
		if(!found) y = np[j];
		//cout << "n_copy = " << n_copy << ", y = " << x << endl;
		for(int z=0;z<m && !found;z++){
		    if(i == z || j == z){
			continue;
		    }
		    if(n_copy <= np[z]){
			break;
		    }
		    n_copy -= np[z];
		    if(!found) w = np[z];
		    //cout << "n_copy = " << n_copy << ", z = " << x << endl;
		    if(x != y && x != w && x != n_copy && y != w && y != n_copy && w != n_copy){
			found = true;
		    }
		    if(!found) n_copy += np[z];
		}
		if(!found) n_copy += np[j];
	    }
	    if(!found) n_copy += np[i];
	}

	if(!found){
	    cout << "NO" << endl;
	}else{
	    cout << "YES" << endl;
	    cout << x << " " << y << " " << w << " " << n_copy << endl;
	}

    }

    return 0;
}

