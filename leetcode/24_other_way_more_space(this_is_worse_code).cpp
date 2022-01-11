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
	ListNode *swapPairs (ListNode *head) {
		ListNode *node = head, *dummy = new ListNode (- 1);
		head = dummy;
		while (node != NULL) {
			if (node -> next == NULL) {
				dummy -> next = new ListNode (node -> val);
				break;
			}
			dummy -> next = new ListNode (node -> next -> val);
			dummy -> next -> next = new ListNode (node -> val);
			ListNode *tmp = node -> next -> next;
			node = tmp;
			dummy = dummy -> next -> next;
		}
		return head -> next;
	}
};
