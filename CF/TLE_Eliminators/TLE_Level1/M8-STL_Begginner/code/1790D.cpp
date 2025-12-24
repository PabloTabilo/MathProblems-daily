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
    int t;
    cin >> t;
    while(t--){
	int n;
	cin >> n;
	map<int, int> f;
	for(int i=0;i<n;i++){
	    int a;
	    cin >> a;
	    f[a]++;
	}
	//cout << "f: "; for(auto p : f) cout << "{"<< p.first << "," << p.second <<"} ";cout << endl;
	int cnt = 0;
	auto curr = f.begin();
	auto nxt = f.begin();
	int last = -1;
	int times = 0;
	while(!f.empty()){
	    auto p1 = *curr;
	    times++;
	    //cout << "*curr = " << p1.first << ", " << p1.second << endl;
	    //cout << "last = " << last << endl;
	    curr->second--;
	    nxt = next(curr);
	    // first value or are consecutive
	    if(last == -1 || ( (curr != f.end()) && ( (p1.first - last) == 1) ) ) {
		last = p1.first;
	    }
	    // not consecutive
	    else{
		// one large doll
		cnt++;
		curr->second++;
		last = -1;
	    }
    	    
	    //cout << "pre erase >> f: "; for(auto p : f) cout << "{"<< p.first << "," << p.second <<"} ";cout << endl;

	    if(curr->second == 0){
		f.erase(curr);
	    }

	    if(last != -1) curr = nxt;

	    //cout << "new f: "; for(auto p : f) cout << "{"<< p.first << "," << p.second <<"} ";cout << endl;
	    
	    if(curr == f.end() && !f.empty()){
		curr = f.begin();
	    }
	    //cout << "cnt = " << cnt << endl;
	    //cout << "------------------------------------------" << endl;
	    /*
	    if(times > 10){
		break;
	    }
	    */
	}
	if(last != -1){
	    cnt++;
	}
	//cout << "cnt = ";
	cout << cnt;
	cout << '\n'; 
	//cout << endl;
    }

    return 0;
}

