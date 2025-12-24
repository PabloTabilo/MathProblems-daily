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
void readMe(string & s){
    char aux;
    while(cin.peek() != '\n' && cin >> aux){
	if(aux == ';' || aux == '-' || aux == '_'){
	    continue;
	}
	s.push_back(tolower(aux));
    }
    cin.ignore();
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s1, s2, s3;
    readMe(s1);
    readMe(s2);
    readMe(s3);
    int n;
    cin >> n;
    cin.ignore();
    string op1 = s1 + s2 + s3;
    string op2 = s1 + s3 + s2;
    string op3 = s2 + s1 + s3;
    string op4 = s2 + s3 + s1;
    string op5 = s3 + s1 + s2;
    string op6 = s3 + s2 + s1;
    /*
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "op1 = " << op1 << endl;
    cout << "op2 = " << op2 << endl;
    cout << "op3 = " << op3 << endl;
    cout << "op4 = " << op4 << endl;
    cout << "op5 = " << op5 << endl;
    cout << "op6 = " << op6 << endl;
    */
    while(n--){
	string s4;
	readMe(s4);
	//cout << "s4 = " << s4 << endl;
	if(s4 == op1 || s4 == op2 || s4 == op3 || s4 == op4 || s4 == op5 || s4 == op6){
	    cout << "ACC\n";
	}else{
	    cout << "WA\n";
	}
    }
    return 0;
}

