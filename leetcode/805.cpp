class Solution {
public:
	bool splitArraySameAverage(vector<int>& nums) {

		// AVERAGE OF BOTH ARRAYS WOULD BE AVERAGE OF
		// TOTAL ARRAY. LET'S CALCULATE IT.

		long long sum = accumulate(nums.begin(), nums.end(), 0LL);

		// AVERAGE WOULD BE SUM / nums.size()

		int n = nums.size();

		// ONE WAY IS THE FOLLOWING

		/*
		vector<vector<int>> dp(n + 1, vector<int>(sum + 1, - 1));

		// WE CAN SEE WHICH SUMS ARE POSSIBLE IN HOW MANY MOVES

		dp[0][0] = 0;

		for(int i = 0; i < n - 1; i++){
		    for(int su = 0; su <= sum - nums[i]; su++){
		        if(dp[i][su] != - 1){
		            int next_sum = su + nums[i];
		            if(next_sum * n == sum * dp[i][su]){
		                return true;
		            }
		            dp[i + 1][su + nums[i]] = dp[i][su] + 1;
		            dp[i + 1][su] = dp[i][su];
		        }
		    }
		}
		*/

		// OTHER WAY IS THE FOLLOWING

		int siz = n / 2;

		// WE TRY TO SOLVE IN O(2 ^ 15)

		vector<set<int>>possible(siz + 1);

		possible[0].emplace(0);

		for (auto i : nums) {

			// LOOP IS REVERSE BECAUSE WE DONT WANT TO COUNT
			// SAME ELEMENT TWICE . SMALLER GROUP INFLUENCES
			// THE LARGER GROUP AND HENCE IS PROBLEMATIC !!!

			for (int lev = siz; lev >= 1; lev--) {
				for (auto las : possible[lev - 1]) {
					possible[lev].emplace(las + i);
				}

				for (auto j : possible[lev]) {
					if (j * n == sum * lev)
						return true;
				}
			}
		}

		return false;
	}
};