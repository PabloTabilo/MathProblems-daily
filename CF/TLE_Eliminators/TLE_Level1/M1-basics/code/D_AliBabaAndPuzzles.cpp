#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll res, sign1, sign2;
    string ope = "*+-";
    bool isPossible = false;
    for(int i=0;i<3 && !isPossible;i++){
	for(int j=0;j<3 && !isPossible;j++){
	    if(i == j){
		continue;
	    }
	    if(i == 0){
		res = a*b;
		sign2 = (j == 1 ? 1LL : -1LL);
		res += (c*sign2);
	    }else if(j == 0){
		res = b*c;
		sign1 = (i == 1 ? 1LL : -1LL);
		res *= sign1;
		res += a;
	    }else{
		sign1 = (i == 1 ? 1LL : -1LL);
		sign2 = (j == 1 ? 1LL : -1LL);
		res = a + (b*sign1) + (c*sign2);
	    }
	    if(res == d){
		isPossible = true;
		break;
	    }
	}
    }
    if(isPossible){
	cout << "YES" << endl;
    }else{
	cout << "NO" << endl;
    }

    return 0;
}

