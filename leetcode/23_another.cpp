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
	ListNode *mergeKLists (vector<ListNode *> &A) {
		priority_queue<int>s;
		for (auto i : A) {
			while (i != NULL) {
				s.push (- (i->val));
				i = i->next;
			}
		}
		ListNode *a = new ListNode (-1);
		ListNode *B = a;
		while (s.empty() == 0) {
			B->next = new ListNode (-s.top());
			s.pop();
			B = B->next;
		}
		return a->next;
	}
};
