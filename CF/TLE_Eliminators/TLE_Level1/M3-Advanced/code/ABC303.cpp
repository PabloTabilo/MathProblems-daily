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
    int N, M;
    cin >> N >> M;

    bool ** conn = new bool*[N+1];
    for(int i=0;i<(N+1);i++){
	conn[i] = new bool[N+1]();
    }

    int ** A = new int*[M];
    for(int i=0;i<M;i++){
	A[i] = new int[N];
    }

    for(int i=0;i<M;i++){
	for(int j=0;j<N;j++){
	    cin >> A[i][j];
	}
    }

    for(int i=0;i<M;i++){
	for(int j=0;j<N;j++){
	    if((j-1) >= 0){
		conn[A[i][j]][A[i][j-1]] = true;
		conn[A[i][j-1]][A[i][j]] = true;
	    }
	    if((j+1)<M){
		conn[A[i][j]][A[i][j+1]] = true;
		conn[A[i][j+1]][A[i][j]] = true;
	    }
	}
    }
    int ans = 0;
    for(int i=1;i<=N;i++){
	int cnt = 0;
	for(int j=1;j<=N;j++){
	    if(i == j) continue;
	    if(!conn[i][j]){
		cnt++;
		conn[j][i] = true; // not double count
	    }
	}
	ans += cnt;
    }

    cout << ans << '\n';

    return 0;
}

