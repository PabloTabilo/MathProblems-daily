#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if(n >= 0){
	cout << n << endl;
	return 0;
    }
    n *= -1;
    int c1 = n / 10; // n-1 digits
    int c2 = n / 100;
    c2 *= 10;
    int x = n % 10;
    c2 += x;
    
    c1 *= -1;
    c2 *= -1;
    //cout << "c1 = " << c1 << " vs c2 = " << c2 << endl;
    //cout << "ans = ";
    cout << max(c1, c2) << endl;
    return 0;
}

