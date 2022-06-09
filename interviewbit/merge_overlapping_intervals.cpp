/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
static bool cmp (Interval a, Interval b) {
	return a.start < b.start;
}
vector<Interval> Solution::merge (vector<Interval> &A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	sort (A.begin(), A.end(), cmp);
	vector<Interval> v;
	for (int i = 0; i < A.size(); i++) {
		int j = i + 1, st = A[i].start, en = A[i].end;
		while (j < A.size() and A[j].start <= en) {
			en = max (en, A[j].end);
			j++;
		}
		v.emplace_back (st, en);
		i = j - 1;
	}
	return v;
}

