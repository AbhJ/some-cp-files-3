
/**
 * @author      : abhj
 * @created     : Monday Mar 07, 2022 22:16:24 IST
 * @filename    : b.cpp
 */

#include "bits/stdc++.h"
#define int          long long int
#define mp           make_pair
#define pb           emplace_back
#define F            first
#define S            second
using vi       =     std::vector<int>;
using vvi      =     std::vector<vi>;
using pii      =     std::pair<int, int>;
using vpii     =     std::vector<pii>;
using vvpii    =     std::vector<vpii>;
using namespace std;
const int inf  =     1e18 + 10;
const int N    =     2e6 + 10;
int _mergeSort (int arr[], int temp[], int left, int right);
int merge (int arr[], int temp[], int left, int mid,
		   int right);

/* This function sorts the
   input array and returns the
number of inversions in the array */
int mergeSort (int arr[], int array_size) {
	int temp[array_size];
	return _mergeSort (arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function
  that sorts the input array and
returns the number of inversions in the array. */
int _mergeSort (int arr[], int temp[], int left, int right) {
	int mid, inv_count = 0;
	if (right > left) {
		/* Divide the array into two parts and
		call _mergeSortAndCountInv()
		for each of the parts */
		mid = (right + left) / 2;
		/* Inversion count will be sum of
		inversions in left-part, right-part
		and number of inversions in merging */
		inv_count += _mergeSort (arr, temp, left, mid);
		inv_count += _mergeSort (arr, temp, mid + 1, right);
		/*Merge the two parts*/
		inv_count += merge (arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
int merge (int arr[], int temp[], int left, int mid,
		   int right) {
	int i, j, k;
	int inv_count = 0;
	i = left; /* i is index for left subarray*/
	j = mid; /* j is index for right subarray*/
	k = left; /* k is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else {
			temp[k++] = arr[j++];
			/* this is tricky -- see above
			explanation/diagram for merge()*/
			inv_count = inv_count + (mid - i);
		}
	}
	/* Copy the remaining elements of left subarray
	(if there are any) to temp*/
	while (i <= mid - 1)
		temp[k++] = arr[i++];
	/* Copy the remaining elements of right subarray
	   (if there are any) to temp*/
	while (j <= right)
		temp[k++] = arr[j++];
	/*Copy back the merged elements to original array*/
	for (i = left; i <= right; i++)
		arr[i] = temp[i];
	return inv_count;
}
int n, a[N], b[N], A[N], B[N];
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], A[i] = a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i], B[i] = b[i];
	sort (A, A + n);
	sort (B, B + n);
	for	(int i = 0; i < n; i++)
		if (A[i] != B[i]) {
			cout << "No";
			return;
		}
	for (int i = 1; i < n; i++) {
		if (A[i] == A[i - 1]) {
			cout << "Yes";
			return;
		}
	}
	cout << (((mergeSort (a, n) & 1) == (mergeSort (b, n) & 1)) ? "Yes" : "No");
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
