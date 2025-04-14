class Solution {
public:
	int minimumSeconds (vector<int>& nums) {
		int n = nums.size();
		vector<int> a = nums;
		for (int i = 0; i < n; i++)
			a.emplace_back (nums[i]);
		// now try to find the distance to nearest occurence
		map <int, int> m, dis;
		n <<= 1;
		for (int i = 0; i < n; i++) {
			if (m.count (a[i])) {
				dis[a[i]] = max (dis[a[i]], (i - m[a[i]] + n / 2 - 1) % (n / 2));
			}
			m[a[i]] = i;
		}
		int ans = 1e9;
		for (auto [x, y] : dis)
			ans = min ((y + 1) / 2, ans);
		return ans;
	}
};