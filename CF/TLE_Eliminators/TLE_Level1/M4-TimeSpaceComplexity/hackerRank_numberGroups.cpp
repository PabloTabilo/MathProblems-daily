#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sumOfGroup' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER k as parameter.
 */

long sumOfGroup(int K) {
    // Return the sum of the elements of the k'th group.
    ll li = 1;
    int k;
    for(k=1;k<K;k++){
        li = li + k*2;
    }
    ll ls = li + k*2 - 2;
    __int128 S_ls = (__int128)ls * (ls + 1) / 2;
    __int128 S_li = (__int128)li * (li + 1) / 2;
    ll SUM = (ll)(S_ls - S_li);
    ll evenSUM = (SUM - (K-1))/2;
    ll oddSum = (SUM - evenSUM) + li;
    return oddSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    long answer = sumOfGroup(k);

    fout << answer << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

