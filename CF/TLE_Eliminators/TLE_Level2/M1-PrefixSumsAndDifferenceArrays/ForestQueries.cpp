#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace chrono;

/* -- Red black tree for build a set that can get kth position -- */
/* -- not accept duplicates, its possible to implement? -- */
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
    int n, q;
    cin >> n >> q;
    int ** mat = new int*[n];
    ll ** prefix = new ll*[n];
    for(int i=0;i<n;i++){
	prefix[i] = new ll[n]();
	mat[i] = new int[n]();
    }
    for(int i=0;i<n;i++){
	string temp;
	cin >> temp;
	int j = 0;
	for(auto &c : temp){
	    if(c == '.'){
		mat[i][j] = 0;
	    }else{
		mat[i][j] = 1;
	    }
	    j++;
	}
    } 
    /*
    cout << "mat: " << endl;
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    cout << mat[i][j] << " ";
	}
	cout << endl;
    }
    */
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    prefix[i][j] = (ll)mat[i][j];
	    if((i-1) >= 0){
		prefix[i][j] += prefix[i-1][j];
	    }
	    if((j-1) >= 0){
		prefix[i][j] += prefix[i][j-1];
	    }
	    if((i-1)>=0 && (j-1)>=0){
		prefix[i][j] -= prefix[i-1][j-1];
	    }
	}
    }
    /*
    cout << "prefix: " << endl;
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    cout << prefix[i][j] << " ";
	}
	cout << endl;
    }
    cout << endl;
    */
    for(int qi = 0; qi < q; qi++){
	int y1, x1, y2, x2;
	cin >> y1 >> x1 >> y2 >> x2;
	y1--;
	x1--;
	y2--;
	x2--;
	ll area = prefix[y2][x2];
	ll areaUpper = 0;
	ll areaLeft = 0;
	ll areaDiag = 0;
	if((x1-1)>=0){
	    areaUpper = prefix[y2][x1-1];
	}
	if((y1-1)>=0){
	    areaLeft = prefix[y1-1][x2];
	}
	if((x1-1)>=0 && ((y1-1)>=0)){
	    areaDiag = prefix[y1-1][x1-1];
	}
	ll ans = area - areaUpper - areaLeft + areaDiag;
	//cout << "ans = ";
	cout << ans;
	cout << '\n';
	//cout << endl;
    }
    return 0;
}

