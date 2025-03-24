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
	vector<int> p(n);
	for(int i=0;i<n;i++){
	    cin >> p[i];
	}
	bool isPossible = false;
	int g;
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
		if(i == j) continue;
		g = gcd(p[i], p[j]);
		//cout << "gcd("<<p[i]<<","<<p[j]<<") = " << g << endl;
		if(g <= 2){
		    isPossible = true;
		}
	    }
	}
	if(!isPossible){
	    cout << "No" << endl;
	}else{
	    cout << "Yes" << endl;
	}
    }

    return 0;
}

