ListNode *Solution::removeNthFromEnd (ListNode *A, int B) {
	auto t = A;
	int cnt = 0, c = 0;
	while (t != NULL)
		cnt++, t = t->next;
	ListNode *a = new ListNode (-1);
	auto b = a;
	while (A != NULL) {
		c++;
		if (c + B - 1 != cnt)
			b->next = A, b = b->next;
		A = A->next;
	}
	b -> next = NULL;
	if (B > cnt)
		a = a->next;
	return a->next;
}
