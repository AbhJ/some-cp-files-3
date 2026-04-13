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
	int cnt;
	set <int> s;
	bool st;
	void dfs (ListNode* head) {
		if (head == NULL)
			return;
		if (st == 0 and s.count (head -> val)) {
			st = 1;
			cnt++;
		}
		else if (st == 1 and s.count (head -> val) == 0) {
			st = 0;
		}
		dfs (head -> next);
	}
	int numComponents (ListNode* head, vector<int>& nums) {
		for (auto i : nums)
			s.emplace (i);
		dfs (head);
		return cnt;
	}
};