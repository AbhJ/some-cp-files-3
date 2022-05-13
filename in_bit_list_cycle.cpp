/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::detectCycle (ListNode *A) {
	ListNode *a = A, *b = A;
	bool F = 0;
	while (a != NULL and b != NULL and b->next != NULL) {
		a = a->next, b = b->next->next;
		if (a == b) {
			F = 1;
			break;
		}
	}
	if (F == 0)
		return NULL;
	a = A;
	// https://www.codingninjas.com/blog/2020/09/09/floyds-cycle-detection-algorithm
	// logic explained well here
	while (a != b) {
		a = a->next;
		b = b->next;
	}
	return a;
}
