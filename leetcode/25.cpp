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
	int cntNodes (ListNode *A, int B) {
		int cnt = 0;
		while (A != NULL and cnt < B) {
			cnt++;
			A = A -> next;
		}
		return cnt;
	}
	ListNode *reverseKGroup (ListNode *A, int B) {
		if (cntNodes (A, B) != B)
			return A;
		ListNode *cur = A, *next, *prev = new ListNode (- 1);
		prev -> next = cur;
		int cnt = B;
		while (cnt-- and cur != NULL) {
			next = cur -> next;
			cur -> next = prev;
			prev = cur;
			cur = next;
		}
		if (A -> next != NULL)
			A -> next = reverseKGroup (cur, B);
		return prev;
	}
};
