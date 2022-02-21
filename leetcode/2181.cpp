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
	ListNode *mergeNodes (ListNode *head) {
		ListNode *start = head, *last = head;
		int runSum = 0;
		while (head != NULL) {
			runSum += head -> val;
			if (head -> val == 0 and runSum != 0) {
				last -> next = new ListNode (runSum);
				last = last -> next;
				runSum = 0;
			}
			head = head -> next;
		}
		return start -> next;
	}
};
