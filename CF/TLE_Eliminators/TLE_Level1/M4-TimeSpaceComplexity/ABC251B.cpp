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

static constexpr int MAXW = 1'000'000;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll N, W;
    cin >> N >> W;
    vector<int>A(N);
    for(int i=0;i<N;i++){
	cin >> A[i];
    }
    static bitset<MAXW+1> dp0, dp1, dp2, dp3; 
    dp0.reset(); dp1.reset(); dp2.reset(); dp3.reset();
    dp0[0] = 1; // sum = 0 -> always track sum 0
    for(auto a : A){
	if(a > W) continue;
	dp3 |= (dp2 << a);
	dp2 |= (dp1 << a);
	dp1 |= (dp0 << a);
    }
    auto good = dp3 | dp2 | dp1;
    int cnt = 0;
    for(int s = 1; s<=W;s++){
	if(good[s]) cnt++;
    }
    //cout << "cnt = ";
    cout << cnt << endl;
    return 0;
}

