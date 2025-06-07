#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

void printDouble(double d){
    // fix precision, the fixed is for evit rounding 
    // rounding can be different for each compiler
    cout << fixed << setprecision(11) << d << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, a, b;
    cin >> n;
    cin >> a;
    cin >> b;
    bool isPossible = false;
    int x = 0;
    int y = 0;
    for(int i=0;i<=n;i++){
	int diff = n - (b*i);
	if(diff >= 0){
	    if(diff % a == 0){
		isPossible = true;
		y = i;
		x = diff / a;
		break;
	    }
	}else{
	    break;
	}
    }
    if(isPossible){
	cout << "YES\n";
	cout << x << " " << y << "\n";
    }else{
	cout << "NO\n";
    }

    return 0;
}

