/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::rotateRight (ListNode *A, int B) {
	ListNode *leftHead = new ListNode (-1), * rightHead = new ListNode (- 1), * left = leftHead, * right = rightHead;
	int cnt = 0;
	ListNode *tmp = A;
	while (tmp != NULL) {
		tmp = tmp -> next;
		cnt++;
	}
	if (cnt == 0)
		return A;
	B %= cnt;
	for (int i = 0; i < cnt - B; i++) {
		right -> next = A;
		A = A -> next;
		right = right -> next;
	}
	for (int i = 0; i < B; i++) {
		left -> next = A;
		A = A -> next;
		left = left -> next;
	}
	left -> next = rightHead -> next;
	right -> next = NULL;
	return leftHead -> next;
}

