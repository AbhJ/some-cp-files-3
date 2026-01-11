class Solution {
public:
	int countTriplets (vector<int>& nums) {
		int cn[1 << 16], ans = 0;
		fill (cn, cn + (1 << 16), 0);
		for (int f : nums)
			for (int s : nums)
				cn [f & s]++;
		for (int f : nums)
			for (int i = 0; i < (1 << 16); i++)
				if ((f & i) == 0)
					ans += cn[i];
		return ans;
	}
};