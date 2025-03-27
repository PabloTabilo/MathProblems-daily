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
	int odds = 1;
	for(int i=1;i<=n;i++){
	    cout << odds << " ";
	    odds += 2;
	}
	cout << endl;
    }
    return 0;
}

