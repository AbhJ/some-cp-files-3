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
		ListNode* tmp = head;
		while (head != NULL) {
			ListNode* nex = head;
			while (nex -> next != NULL and nex -> next -> val == nex -> val)
				nex = nex -> next;
			head -> next = nex -> next;
			head = head -> next;
		}
		return tmp;
	}
};