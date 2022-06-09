class Solution {
public:
	int jump (vector<int> &nums) {
		int end = nums[0], can_go = 0, cost = 1;
		for (int i = 0; i < nums.size(); i++) {
			can_go = max (can_go, i + nums[i]);
			if (i == end and i != nums.size() - 1) {
				cost ++;
				end = can_go;
			}
		}
		return (nums.size() != 1 ? cost : 0);
	}
};
