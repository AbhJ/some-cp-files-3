/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode *Solution::copyRandomList (RandomListNode *A) {
	RandomListNode *a, *s = A, *c;
	c = a;
	map<RandomListNode *, RandomListNode *>m;
	while (A != NULL) {
		m[A] = new RandomListNode (- 1);
		A = A->next;
	}
	A = s;
	while (s != NULL) {
		m[s]->next = m[s->next];
		m[s]->random = m[s->random];
		m[s]->label = s->label;
		s = s->next;
	}
	return m[A];
}
