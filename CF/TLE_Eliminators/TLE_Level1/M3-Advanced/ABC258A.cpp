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
    int k;
    cin >> k;

    int hours = k / 60;
    k -= (hours * 60);

    int hoursAns = 21 + hours;
    int minsAns = k;
    cout << hoursAns << ":";
    if(k < 10){
	cout << "0" << minsAns << '\n';
    }else{
	cout << minsAns << '\n';
    }

    return 0;
}

