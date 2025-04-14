class Solution {
public:
	int maxIncreasingGroups (vector<int>& usageLimits) {
		int n = usageLimits.size(), grps = 0;
		sort (usageLimits.begin(), usageLimits.end());
		long long eleCnt = 0;
		for (int i = 0; i < n; i++) {
			long long x = i + 1;
			eleCnt += usageLimits[i];
			// now checking if we can fit all the grp + 1 boxes
			// with ith elements
			long long req = (((grps + 1LL) * (grps + 2LL)) >> 1LL);
			if (req <= eleCnt) {
				// we directly create new group and move on
				grps++;
				// they will restructure themselves when needed
				// examples : [2, 2, 2]
				// we need to make sure at every level grouping
				// is possible
				/*
				    Step 1
				    0 0

				    Step 2
				    1
				    0 0 1

				    Step 3
				    2
				    2 1
				    0 0 1
				*/
			}
		}
		return grps;
	}
};