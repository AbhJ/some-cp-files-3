class Solution {
public:
	int numOfSubarrays (vector<int>& arr, int k, int threshold) {
		int n = arr.size(), sum = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			sum += arr[i];
			if (i < k - 1)
				continue;
			if (i != k - 1)
				sum -= arr[i - k];
			if (sum >= threshold * k) {
				cnt++;
			}
		}
		return cnt;
	}
};