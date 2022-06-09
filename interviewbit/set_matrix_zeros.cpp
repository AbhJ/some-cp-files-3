void Solution::setZeroes (vector<vector<int> > &A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int n = A.size(), m = A[0].size();
	bool top_row = 0, top_col = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (A[i][j] == 0) {
				A[i][0] = A[0][j] = 0;
				if (i == 0)
					top_row = 1;
				if (j == 0)
					top_col = 1;
			}
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++) {
			if (A[i][0] == 0 or A[0][j] == 0)
				A[i][j] = 0;
		}
	if (top_row)
		for (int i = 0; i < m; i++)
			A[0][i] = 0;
	if (top_col)
		for (int i = 0; i < n; i++)
			A[i][0] = 0;
}

