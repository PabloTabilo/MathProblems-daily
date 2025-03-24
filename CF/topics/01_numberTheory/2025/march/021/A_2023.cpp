#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int n, k;
	cin >> n >> k;
	int curr = 2023;
	bool isPossible = true;
	vector<int> b(n);
	for(int i=0;i < n; i++){
	    cin >> b[i];
	    if(curr % b[i] == 0){
		curr /= b[i];
	    }else{
		isPossible = false;
	    }
	}
	if(!isPossible){
	    cout << "NO" << endl;
	}else{
	    cout << "YES" << endl;
	    // possible curr values
	    // 2023 = 7*17*17, 289 = 17*17, 119 = 7*17, 17, 7
	    cout << curr << " ";
	    k--;
	    while(k--) cout << 1 << " ";
	    cout << endl;
	}
    }
    return 0;
}

