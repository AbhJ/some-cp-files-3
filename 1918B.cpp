#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <numeric>
#include <vector>
#include <iterator>
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
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
int n;

int merge (vector<int> &arr, int low, int mid, int high) {
	vector<int> temp; // temporary array
	int left = low;      // starting index of left half of arr
	int right = mid + 1;   // starting index of right half of arr
	//Modification 1: cnt variable to count the pairs:
	int cnt = 0;
	//storing elements in the temporary array in a sorted manner//
	while (left <= mid && right <= high) {
		if (arr[left] <= arr[right]) {
			temp.push_back (arr[left]);
			left++;
		}
		else {
			temp.push_back (arr[right]);
			cnt += (mid - left + 1); //Modification 2
			right++;
		}
	}
	// if elements on the left half are still left //
	while (left <= mid) {
		temp.push_back (arr[left]);
		left++;
	}
	//  if elements on the right half are still left //
	while (right <= high) {
		temp.push_back (arr[right]);
		right++;
	}
	// transfering all elements from temporary to arr //
	for (int i = low; i <= high; i++) {
		arr[i] = temp[i - low];
	}
	return cnt; // Modification 3
}

int mergeSort (vector<int> &arr, int low, int high) {
	int cnt = 0;
	if (low >= high) return cnt;
	int mid = (low + high) / 2 ;
	cnt += mergeSort (arr, low, mid); // left half
	cnt += mergeSort (arr, mid + 1, high); // right half
	cnt += merge (arr, low, mid, high); // merging sorted halves
	return cnt;
}

int numberOfInversions (vector<int>a, int n) {
	// Count the number of pairs:
	return mergeSort (a, 0, n - 1);
}

void solve() {
	cin >> n;
	vector <pii> a (n), b (n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i].F;
		b[i].S = a[i].F;
	}
	for (int i = 0; i < n; i ++) {
		cin >> a[i].S;
		b[i].F = a[i].S;
	}
	sort (a.begin(), a.end());
	sort (b.begin(), b.end());
	vi A1, A2, B1, B2;
	for (auto i : a)
		A1.pb (i.F), A2.pb (i.S);
	for (auto i : b)
		B1.pb (i.F), B2.pb (i.S);
	if (numberOfInversions (A1, n) + numberOfInversions (A2,
	        n) < numberOfInversions (B1, n) + numberOfInversions (B2, n)) {
		for (auto i : A1)
			cout << i << " ";
		cout << "\n";
		for (auto i : A2)
			cout << i << " ";
	}
	else {
		for (auto i : B2)
			cout << i << " ";
		cout << "\n";
		for (auto i : B1)
			cout << i << " ";
	}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int t;
	cin >> t;
	while (t--) {
		solve();
		cout << "\n";
	}
	return 0;
}