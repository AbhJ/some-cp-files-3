class MedianFinder {
public:
	multiset<int> s1;
	multiset<int> s2;

	void balance() {
		if (s1.size() == s2.size() || s1.size() == s2.size() + 1)
			return;
		if ((s1.size() + s2.size()) & 1) {
			int e = *s2.begin();
			s2.erase (s2.begin());
			s1.emplace (e);
		}
		else {
			int e = *s1.rbegin();
			s1.erase (prev (s1.end()));
			s2.emplace (e);
		}
	}

	void addNum (int num) {
		double median = findMedian();
		if (num > median)
			s2.emplace (num);
		else
			s1.emplace (num);
		balance();
	}

	void deleteNum (int num) {
		if (s1.count (num))
			s1.erase (s1.find (num));
		else
			s2.erase (s2.find (num));
		balance();
	}

	double findMedian() {
		if (s1.size() == 0)
			return -1;
		if (s1.size() == s2.size())
			return ((double) * s1.rbegin() + (double) * s2.begin()) / (double) 2;
		else
			return *s1.rbegin();
	}
};

class Solution {
public:

	vector<double> medianSlidingWindow (vector<int> &nums, int k) {
		int n = nums.size();
		vector<double>v;
		MedianFinder m;
		for (int i = 0; i < n; i++) {
			if (i >= k)
				m.deleteNum (nums[i - k]);
			m.addNum (nums[i]);
			if (i > k - 2)
				v.emplace_back (m.findMedian());
		}
		return v;
	}
};

