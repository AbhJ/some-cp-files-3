class Solution {
public:
	vector<int> pivotArray (vector<int> &nums, int pivot) {
		vector<int>v;
		for (auto i : nums) {
			if (i < pivot)
				v.emplace_back (i);
		}
		for (auto i : nums) {
			if (i == pivot)
				v.emplace_back (i);
		}
		for (auto i : nums) {
			if (i > pivot)
				v.emplace_back (i);
		}
		return v;
	}
};
