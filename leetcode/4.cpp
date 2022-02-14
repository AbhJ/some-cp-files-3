class Solution {
public:
	double findMedianSortedArrays (vector<int> &nums1, vector<int> &nums2) {
		double ans = - 1;
		int n = nums1.size(), m = nums2.size();
		int l1 = 0, r1 = n, l2 = 0, r2 = m, m1, m2;
		if (! (n + m))
			return n;
		if (n > m)
			return findMedianSortedArrays (nums2, nums1);
		while (l1 <= r1) {
			m1 = ((l1 + r1) >> 1);
			m2 = ((n + m + 1) >> 1) - m1;
			int v1 = (m1 == 0 ? - 1e9 : nums1[m1 - 1]), v2 = (m2 == 0 ? - 1e9 : nums2[m2 - 1]);
			int V1 = (m1 == n ? 1e9 : nums1[m1]), V2 = (m2 == m ? 1e9 : nums2[m2]);
			if (max (v1, v2) <= min (V1, V2)) {
				if ((n + m) & 1)
					return max (v1, v2);
				return (max (v1, v2) + min (V1, V2)) / 2.0;
			}
			if (v1 > V2)
				r1 = m1 - 1;
			else
				l1 = m1 + 1;
		}
		l2 = ((n + m + 1) >> 1) - l1;
		int v1 = (l1 == 0 ? - 1e9 : nums1[l1 - 1]), v2 = (l2 == 0 ? - 1e9 : nums2[l2 - 1]);
		int V1 = (l1 == n ? 1e9 : nums1[l1]), V2 = (l2 == m ? 1e9 : nums2[l2]);
		if ((n + m) & 1)
			return max (v1, v2);
		return (max (v1, v2) + min (V1, V2)) / 2.0;
	}
};
