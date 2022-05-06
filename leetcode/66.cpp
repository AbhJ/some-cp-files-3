class Solution {
public:
	vector<int> plusOne (vector<int> &digits) {
		if ((digits.size() == 1) and (digits[0] == 0)) {
			digits[0]++;
			return digits;
		}
		int i = 0;
		vector<int>B;
		while (i < digits.size() and digits[i] == 0)
			i++;
		for (; i < digits.size(); i++)
			B.push_back (digits[i]);
		if (B.back() == 9) {
			int i = B.size() - 1;
			while (~i and B[i] == 9)
				B[i] = 0, i--;
			if (~i) {
				B[i]++;
				return B;
			}
			vector<int>B1 (B.size() + 1);
			B1[0] = 1;
			for (int i = 1; i <= B.size(); i++)
				B1[i] = B[i - 1];
			return B1;
			assert (0);
		}
		B.back() ++;
		return B;
	}
};
