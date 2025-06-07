#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b;
    cin >> a >> b;
    int mx = max(a, b);
    int mn = min(a, b);
    if(mx % mn == 0){
	cout << "Multiples" << endl;
    }else{
	cout << "No Multiples" << endl;
    }

    return 0;
}

