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
	if(n % 2 == 0){
	    cout << -1 << endl;
	}else{
	    vector<int> p(n);
	    int even = 2;
	    int i = 0;
	    for(;i<n && even < n;i++){
		p[i] = even;
		even += 2;
	    }
	    int odd = 1;
	    for(;i<n && odd <= n;i++){
		p[i] = odd;
		odd += 2;
	    }
	    for(auto x : p){
		cout << x << " ";
	    }
	    cout << endl;
	}
    }

    return 0;
}

