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
		ListNode *headCopy = new ListNode (- 1);
		headCopy -> next = head;
		head = headCopy;
		while (head -> next != NULL and head -> next -> next != NULL) {
			ListNode *first = head -> next, *second = first -> next, *third = second -> next;
			first -> next = third;
			second -> next = first;
			head -> next = second;
			head = first;
		}
		return headCopy -> next;
	}
};
