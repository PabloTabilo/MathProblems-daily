#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    cout << min(a, min(b, c)) << " " << max(a, max(b, c)) << endl;
    return 0;
}

