/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode *partition (ListNode *A, int B) {
		ListNode *smaller = new ListNode (- 1);
		ListNode *bigger = new ListNode (- 1);
		ListNode *headSmaller = smaller, *headBigger = bigger;
		while (A != NULL) {
			if (A -> val < B) {
				smaller -> next = A;
				smaller = smaller -> next;
			}
			else {
				bigger -> next = A;
				bigger = bigger -> next;
			}
			A = A -> next;
		}
		smaller -> next = headBigger -> next;
		bigger -> next = NULL;
		return headSmaller -> next;
	}
};
