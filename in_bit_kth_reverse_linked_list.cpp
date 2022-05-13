/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::reverseList (ListNode *A, int B) {
	ListNode *head = A, *start, *prev = new ListNode (- 1);
	prev -> next = A;
	int cnt = B;
	while (cnt--) {
		ListNode *tmp = A->next;
		A->next = prev;
		prev = A;
		A = tmp;
	}
	if (A != NULL)
		head->next = reverseList (A, B);
	if (head -> next -> val == - 1)
		head -> next = NULL;
	return prev;
}
