/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::rotateRight (ListNode *A, int k) {
	ListNode *a = A;
	ListNode *B = new ListNode (-1);
	ListNode *D = new ListNode (-1);
	auto C = B, d = D;
	int cnt = 0, c = 0, c1 = 0;
	while (a != NULL)
		a = a->next, cnt++;
	a = A;
	k %= cnt;
	while (c != cnt - k) {
		c++;
		B->next = a;
		a = a->next;
		B = B->next;
	}
	while (a != NULL) {
		c++;
		D->next = a;
		a = a->next;
		D = D->next;
	}
	D->next = C->next;
	B->next = NULL;
	return d->next;
}

