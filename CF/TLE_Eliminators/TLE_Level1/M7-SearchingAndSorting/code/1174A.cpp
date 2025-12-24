#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;


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
    vector<ll> A(2*n);
    for(int i=0;i<2*n;i++){
	cin >> A[i];
    }
    sort(A.begin(), A.end());
    ll s1 = 0;
    ll s2 = 0;
    for(int i=0, j=2*n-1;i<j;i++, j--){
	s1 += A[i];
	s2 += A[j];
    }
    if(s1 != s2){
	for(auto x : A) cout << x << " ";
    }else{
	cout << "-1";
    }
    cout << '\n';
    return 0;
}

