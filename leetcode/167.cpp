class Solution {
public:
	vector<int> twoSum (vector<int>& numbers, int target) {
		for (int i = 0; i < numbers.size(); i++) {
			int l = i + 1, r = numbers.size() - 1, m;
			while (l < r) {
				m = l + r >> 1;
				if (numbers[m] >= target - numbers[i])
					r = m;
				else
					l = m + 1;
			}
			if (numbers[i] + numbers[r] == target)
				return vector <int> {++i, ++r};
		}
		return {};
	}
};