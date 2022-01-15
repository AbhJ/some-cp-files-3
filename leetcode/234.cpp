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
	ListNode *forwardNode;
	bool func (ListNode *reverseNode) {
		if (reverseNode == NULL)
			return 1;
		if (func (reverseNode -> next) == false)
			return false;
		bool ans = reverseNode -> val == forwardNode -> val;
		forwardNode = forwardNode -> next;
		return ans;
	}
	bool isPalindrome (ListNode *head) {
		forwardNode = head;
		return func (head);
	}
};
