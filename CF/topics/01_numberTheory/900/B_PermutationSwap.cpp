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
	int g = 0;
	int p;
	for(int i=0;i<n;i++){
	    cin >> p;
	    int diff = abs(p - i - 1);
	    g = gcd(g, diff);
	}
	//cout << "ans = ";
	cout << g << endl;
    }
    return 0;
}

