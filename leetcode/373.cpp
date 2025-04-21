class Solution {
public:
	vector<vector<int>> kSmallestPairs (vector<int>& nums1, vector<int>& nums2,
	                                    int k) {
		vector<vector<int>> ans;
		priority_queue <tuple <int, int, int>> q;
		for (int i = 0; i < min (k, (int) nums2.size()); i++)
			q.emplace (- nums1[0] - nums2[i], 0, i);
		while (k--) {
			tuple <int, int, int> t = q.top();
			q.pop();
			ans.emplace_back (vector<int> {nums1[get<1> (t)], nums2[get<2> (t)]});
			if (get<1> (t) == nums1.size() - 1)
				continue;
			q.emplace (- nums1[get<1> (t) + 1] - nums2[get<2> (t)], get<1> (t) + 1,
			           get<2> (t));
		}
		return ans;
	}
};