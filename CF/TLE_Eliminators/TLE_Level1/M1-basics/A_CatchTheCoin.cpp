#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int x, y;
    for(int i=0;i<n;i++){
	cin >> x >> y;
	int h = y - abs(x);
	int moves = x;
	if(moves > 0){
	    moves *= -1;
	}
	//cout << "moves = " << moves << endl;
	//cout << "h = " << h << endl;
	if((moves-1) <= h){
	    cout << "YES" << endl;
	}else{
	    cout << "NO" << endl;
	}
    }

    return 0;
}

