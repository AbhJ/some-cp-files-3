/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::swapPairs (ListNode *A) {
	if (A == NULL or A->next == NULL)
		return A;
	ListNode *fin = A->next;
	A->next = swapPairs (fin->next);
	fin->next = A;
	return fin;
}
