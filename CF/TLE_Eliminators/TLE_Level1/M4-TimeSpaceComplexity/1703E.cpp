#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int n;
	cin >> n;
	vector<vector<int>> original(n, vector<int>(n, 0));
	string s;
	for(int i=0;i<n;i++){
	    cin >> s;
	    for(int j=0;j<n;j++){
		original[i][j] = s[j]-'0';
	    }
	}

	//cout << "original:\n";for(auto y : original){for(auto x : y){cout << x << " ";}cout << '\n';}cout << '\n';
	int cost = 0;
	int sz = n / 2;
	if(n % 2 == 1){
	    vector<int> midRow = original[sz];
	    //cout << "midRow: "; for(auto x : midRow) cout << x << " "; cout << '\n';
	    vector<int> midCol(n);
	    for(int i=0;i<n;i++){
		midCol[i] = original[i][sz];
	    }
	    //cout << "midCol: "; for(auto x : midCol) cout << x << " "; cout << '\n';
	    for(int i=0;i<n;i++){
		if(midCol[i] != midRow[i]){
		    cost++;
		}
	    }
	}
	//cout << "current cost = " << cost << '\n';
	//cout << "sz of the matrix to comp = " << sz << '\n';
	auto get_portion = [&](int x1, int x2, int y1, int y2){
	    int ** m = new int*[sz];
	    for(int i=0;i<sz;i++){
		m[i] = new int[sz]();
	    }
	    for(int i=x1;i<=x2;i++){
		for(int j=y1;j<=y2;j++){
		    m[i-x1][j-y1] = original[i][j];
		}
	    }
	    return m;
	};

	auto rotateMe = [&](int ** m){
	    int ** mt = new int*[sz];
	    for(int i=0;i<sz;i++){
		mt[i] = new int[sz]();
	    }
	    for(int i=0;i<sz;i++){
		for(int j=0;j<sz;j++){
		    mt[j][sz - i - 1] = m[i][j];
		}
	    }
	    return mt;
	};

	auto printMe = [&](int ** m){
	    for(int i=0;i<sz;i++){
		for(int j=0;j<sz;j++){
		    cout << m[i][j] << " ";
		}
		cout << '\n';
	    }
	    cout << '\n';
	};

	auto get_cost = [&](int ** ma, int ** mb){
	    int cnt = 0;
	    for(int i=0;i<sz;i++){
		for(int j=0;j<sz;j++){
		    if(ma[i][j] != mb[i][j]){
			cnt++;
		    }
		}
	    }
	    return cnt;
	};

	int **m0;
	int **m0t;
	int **m1;
	int bcost = INT_MAX;
	array<int, 4> c00, c01, c11, c10;
	if(n % 2 == 1){
	    c00 = {0, sz-1, 0, sz-1};
	    c01 = {0, sz-1, sz+1, n-1};
	    c11 = {sz+1, n-1, sz+1, n-1};
	    c10 = {sz+1, n-1, 0, sz-1};
	}else{
	    c00 = {0, sz-1, 0, sz-1};
	    c01 = {0, sz-1, sz, n-1};
	    c11 = {sz, n-1, sz, n-1};
	    c10 = {sz, n-1, 0, sz-1};
	}
	// 00 is ref
	{
	    int lcost = cost;
	    m0 = get_portion(c00[0], c00[1], c00[2], c00[3]);
	    //cout << "m0\n";
	    //printMe(m0);
	    m0t = rotateMe(m0);
	    //cout << "m0t\n";
	    //printMe(m0t);
	    m1 = get_portion(c01[0], c01[1], c01[2], c01[3]);
	    //cout << "m1\n";
	    //printMe(m1);
	    lcost += get_cost(m0t, m1);
	    //cout << "curr lcost = " << lcost << '\n';
	    m0t = rotateMe(m0t);
	    //cout << "m0t\n";
	    //printMe(m0t);
	    m1 = get_portion(c11[0], c11[1], c11[2], c11[3]);
	    //cout << "m1\n";
	    //printMe(m1);
	    lcost += get_cost(m0t, m1);
	    //cout << "curr lcost = " << lcost << '\n';
	    m0t = rotateMe(m0t);
	    //cout << "m0t\n";
	    //printMe(m0t);
	    m1 = get_portion(c10[0], c10[1], c10[2], c10[3]);
	    //cout << "m1\n";
	    //printMe(m1);
	    lcost += get_cost(m0t, m1);
	    //cout << "curr lcost = " << lcost << '\n';
	    bcost = min(bcost, lcost);
	    //cout << "curr bcost = " << bcost << '\n';
	}
	// 01 is ref
	{
	    int lcost = cost;
	    m0 = get_portion(c01[0], c01[1], c01[2], c01[3]);
	    m0t = rotateMe(m0);
	    m1 = get_portion(c11[0], c11[1], c11[2], c11[3]);
	    lcost += get_cost(m0t, m1);
	    m0t = rotateMe(m0t);
	    m1 = get_portion(c10[0], c10[1], c10[2], c10[3]);
	    lcost += get_cost(m0t, m1);
	    m0t = rotateMe(m0t);
	    m1 = get_portion(c00[0], c00[1], c00[2], c00[3]);
	    lcost += get_cost(m0t, m1);
	    bcost = min(bcost, lcost);
	}
	// 11 is ref
	{
	    int lcost = cost;
	    m0 = get_portion(c11[0], c11[1], c11[2], c11[3]);
	    m0t = rotateMe(m0);
	    m1 = get_portion(c10[0], c10[1], c10[2], c10[3]);
	    lcost += get_cost(m0t, m1);
	    m0t = rotateMe(m0t);
	    m1 = get_portion(c00[0], c00[1], c00[2], c00[3]);
	    lcost += get_cost(m0t, m1);
	    m0t = rotateMe(m0t);
	    m1 = get_portion(c01[0], c01[1], c01[2], c01[3]);
	    lcost += get_cost(m0t, m1);
	    bcost = min(bcost, lcost);
	}
	// 10 is ref
	{
	    int lcost = cost;
	    m0 = get_portion(c10[0], c10[1], c10[2], c10[3]);
	    m0t = rotateMe(m0);
	    m1 = get_portion(c00[0], c00[1], c00[2], c00[3]);
	    lcost += get_cost(m0t, m1);
	    m0t = rotateMe(m0t);
	    m1 = get_portion(c01[0], c01[1], c01[2], c01[3]);
	    lcost += get_cost(m0t, m1);
	    m0t = rotateMe(m0t);
	    m1 = get_portion(c11[0], c11[1], c11[2], c11[3]);
	    lcost += get_cost(m0t, m1);
	    bcost = min(bcost, lcost);
	}
	cout << bcost << '\n';
    }
    return 0;
}

