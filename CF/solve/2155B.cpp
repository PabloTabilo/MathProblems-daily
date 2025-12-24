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

void pg(char ** grid, int n){
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    cout << grid[i][j];
	}
	cout << '\n';
	//cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	ll n, k;
	cin >> n >> k;
	ll cells = n * n;
	ll d = cells - k;
	char ** grid = new char*[n];
	for(int i=0;i<n;i++){
	    grid[i] = new char[n];
	    for(int j=0;j<n;j++){
		grid[i][j] = 'U';
	    }
	}
	//cout << "cells = " << cells << ", d = " << d << endl;
	if(d == 0){
	    cout << "YES";
	    //cout << endl;
	    cout << '\n';
	    pg(grid, n);
	    continue;
	}
	if(d == 1){
	    cout << "NO";
	    //cout << endl;
	    cout << '\n';
	    continue;
	}
	queue<tuple<int, int, char>> q;
	q.push(make_tuple(n-1, 0, 'R'));
	q.push(make_tuple(n-1, 1, 'L'));
	set<pair<int, int>> vis;	
	while(!q.empty()){
	    auto p = q.front();
	    int x = get<0>(p);
	    int y = get<1>(p);
	    char c = get<2>(p);
	    q.pop();
	    if(vis.find({x,y}) != vis.end()){
		continue;
	    }
	    d -= 1;
	    vis.insert({x, y});
	    grid[x][y] = c;
	    if(d == 0){
		break;
	    }
	    if((x-1)>=0){
		q.push(make_tuple(x-1, y, 'D'));
	    }
	    if((y+1)<n){
		q.push(make_tuple(x,y+1,'L'));
	    }
	}

	cout << "YES";
	cout << '\n';
	//cout << endl;
	pg(grid, n);
    }
    return 0;
}

