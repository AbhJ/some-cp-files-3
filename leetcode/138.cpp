/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* A) {
        Node *a,*s=A,*c;c=a;
    map<Node*,Node*>m;
    while(A!=NULL){
       m[A]=new Node(-1);
       A=A->next;
    }
    A=s;
    while(s!=NULL){
        a=m[s];
        a->next=m[s->next];
        a->random=m[s->random];
        a->val=s->val;
        s=s->next;
    }
    return m[A];
    }
};
