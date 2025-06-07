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
    int n, k;
    cin >> n >> k;
    int * A = new int[n];
    for(int i=0;i<n;i++){
	cin >> A[i];
    }

    for(int ki = 0; ki < k; ki++){
	int search;
	cin >> search;
	int l = 0;
	int r = n;
	int ans = -1;
	while(l < r){
	    int mid = l + (r - l) / 2;
	    if(A[mid] > search){
		r = mid;
	    }else{
		ans = mid;
		l = mid + 1;
	    }
	}
	ans++;
	cout << ans << '\n';
    }
    
    return 0;
}

