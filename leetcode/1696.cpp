class Solution {
public:
	int maxResult (vector<int>& nums, int k) {
		int n = nums.size();
		vector <int> ans (n);
		priority_queue <pair <int, int>> q;
		for (int i = n - 1; ~i; i--) {
			while (q.empty() == 0 and q.top().second > i + k)
				q.pop();
			if (q.empty() == 0)
				ans[i] = q.top().first + nums[i];
			else
				ans[i] = nums[i];
			q.emplace (ans[i], i);
		}
		return ans[0];
	}
};