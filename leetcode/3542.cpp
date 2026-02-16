class Solution {
public:
	int minOperations (vector<int>& nums) {
		deque <int> inc = {0};
		int n = nums.size(), ans = 0;
		for (int i = 0; i < n; i++) {
			while (inc.back() > nums [i])
				inc.pop_back();
			if (inc.back() != nums[i]) {
				// cout << i << " ";
				inc.push_back (nums[i]);
				ans++;
			}
			// for (int j: inc) {
			//     cout << j << " ";
			// }
			// cout << "\n";
		}
		return ans;
	}
};