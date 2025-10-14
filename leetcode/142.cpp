/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *detectCycle (ListNode *head) {
		ListNode* hare = head, * mouse = head;
		int cnt = 0;
		do {
			if (hare == NULL or mouse == NULL or hare -> next == NULL)
				return NULL;
			hare = hare -> next -> next;
			mouse = mouse -> next;
		}
		while (hare != mouse);
		mouse = head;
		while (hare != mouse) {
			hare = hare -> next;
			mouse = mouse -> next;
			cnt++;
		}
		return hare;
	}
};