class Solution {
public:
	int rangeBitwiseAnd (int left, int right) {
		if (left == 0)
			return 0;
		int ans = 0;
		for (int i = log2 (max (left, right)); ~ i; i--) {
			if (((1 << i) & left) ^ ((1 << i) & right))
				break;
			ans |= (1 << i) & left;
		}
		return ans;
	}
};