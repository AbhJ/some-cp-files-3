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
	ListNode* deleteDuplicates (ListNode* head) {
		if (head == NULL)
			return head;
		ListNode* nex = head;
		bool F = 0;
		while (nex -> next != NULL and nex -> next -> val == nex -> val) {
			nex = nex -> next;
			F = 1;
		}
		if (F == 1)
			return deleteDuplicates (nex -> next);
		head -> next = deleteDuplicates (nex -> next);
		return head;
	}
};