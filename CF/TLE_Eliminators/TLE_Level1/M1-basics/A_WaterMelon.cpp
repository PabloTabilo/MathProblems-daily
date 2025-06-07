#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int w;
    cin >> w;
    if((w % 2 != 0) || w <= 2){
	cout << "NO" << endl;
    }else{
	cout << "YES" << endl;
    }

    return 0;
}

