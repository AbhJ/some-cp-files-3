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
	ListNode *deleteMiddle (ListNode *head) {
		ListNode ptr (0, head);
		ListNode *ptrx = & ptr, * ptr2x = & ptr;
		while (ptr2x -> next and ptr2x -> next -> next) {
			ptrx = ptrx -> next;
			ptr2x = ptr2x -> next -> next;
		}
		ptrx -> next = ptrx -> next -> next;
		return ptr.next;
	}
};
