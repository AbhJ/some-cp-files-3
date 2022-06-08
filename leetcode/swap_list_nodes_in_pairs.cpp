/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::swapPairs (ListNode *A) {
	if (A == NULL)
		return A;
	ListNode *nex = A -> next;
	if (nex == NULL)
		return A;
	A -> next = swapPairs (nex -> next);
	nex -> next = A;
	return nex;
}

