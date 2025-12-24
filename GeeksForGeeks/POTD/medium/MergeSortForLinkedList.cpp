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

class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* buildList(vector<int> vals){
    if(vals.empty()) return nullptr;
    Node * head = new Node(vals[0]);
    Node * curr = head;
    for(size_t i = 1; i < vals.size(); i++){
	curr->next = new Node(vals[i]);
	curr = curr->next;
    }
    return head;
}

Node* mergeOrder(Node * a, Node * b){
    Node dummy(0);
    Node * tail = &dummy;
    while(a && b){
        if(a->data <= b->data){
	    tail->next = a;
	    a = a->next;
	}else{
	    tail->next = b;
	    b = b->next;
	}
	tail = tail->next;
    }
    tail->next = (a ? a : b);
    return dummy.next;
}

Node * get_mid(Node * head){
    Node * slow = head;
    Node * fast = head->next;
    while(fast && fast->next){
	slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void pL(Node * h){
    Node * loop = h;
    while(loop){
        cout << loop->data << " ";
        loop = loop->next;
    }
    cout << endl;
}

Node * merge(Node * l){
    if(!l || !l->next){
        return l;
    }
    
    Node * mid = get_mid(l);
    Node * r = mid->next;
    mid->next = nullptr;

    Node * leftPortion = merge(l);
    Node * rightPortion = merge(r);
    return mergeOrder(leftPortion, rightPortion);
}


class Solution {
  public:
    Node* mergeSort(Node* head) {
        // code here
        return merge(head);
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solution sol;
    {
	vector<int> vals1 = {3, 5, 2, 4, 1};
	Node * h1 = buildList(vals1);
	cout << "pre merge: ";
	pL(h1);
	Node * h1o = sol.mergeSort(h1);
	cout << "post merge: ";
	pL(h1o);
    }
   /* 
    {
	vector<int> vals1 = {4, 2, 4, 3, 2, 1};
	Node * h1 = buildList(vals1);
	Node * h1o = sol.mergeSort(h1);
    }
    {
	vector<int> vals1 = {41};
	Node * h1 = buildList(vals1);
	Node * h1o = sol.mergeSort(h1);
    }
    {
	vector<int> vals1 = {};
	Node * h1 = buildList(vals1);
	Node * h1o = sol.mergeSort(h1);
    }
    {
	vector<int> vals1 = {391, 41};
	Node * h1 = buildList(vals1);
	Node * h1o = sol.mergeSort(h1);
    }
    {
	vector<int> vals1 = {1, 2, 3, 11, 123, 99, 1072};
	Node * h1 = buildList(vals1);
	Node * h1o = sol.mergeSort(h1);
    }
    */
    return 0;
}

