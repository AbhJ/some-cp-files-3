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
	ListNode* removeNodes(ListNode* head) {
		stack<ListNode*>s;
		ListNode* h = head = new ListNode(1e5, head);
		s.emplace(head);
		head = head -> next;
		while(head != NULL){
			while(s.top() -> val < head -> val)
				s.pop();
			s.top() -> next = head;
			s.emplace(head);
			head = head -> next;
		}
		return h -> next;
	}
};