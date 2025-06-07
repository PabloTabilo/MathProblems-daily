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
    int n;
    cin >> n;

    int r = n % 5;
    int lower = n - r;
    int upper = n + (5 - r);
    int diffL = n - lower;
    int diffU = upper - n;
    if(diffL < diffU){
	cout << lower << '\n';
    }else{
	cout << upper << '\n';
    }
    return 0;
}

