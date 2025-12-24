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
	string president;
	int ans = 1;
	for(int i=0;i<n;i++){
	    string t;
	    cin >> t;
	    if(i == 0){
		president = t;
	    }else{
		if(president == t){
		    ans++;
		}
	    }
	}
	cout << ans << endl;
    }

    return 0;
}

