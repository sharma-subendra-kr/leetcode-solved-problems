// 1539. Kth Missing Positive Number
// https://leetcode.com/problems/kth-missing-positive-number/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

// int findKthPositive(vector<int> &arr, int k) {
// 	//
// 	int idx = 0;
// 	int sum = 0;
// 	for (int i = 0; i < arr.size(); i++) {
// 		if (i == 0) {
// 			sum += arr[i] - 0 - 1;
// 		} else {
// 			sum += arr[i] - arr[i - 1] - 1;
// 		}
// 		if (sum >= k) {
// 			idx = i;
// 			break;
// 		}
// 	}

// 	if (sum >= k) {
// 		int right = arr[idx] - 1;
// 		while (right > 0 && sum != k) {
// 			sum--;
// 			right--;
// 		}
// 		return right;
// 	}
// 	return k - sum + arr[arr.size() - 1];
// }

// int findKthPositive(vector<int> &arr, int k) {
// 	//
// 	int low = 0;
// 	int high = arr.size() - 1;
// 	int diff = 0;
// 	int mid = 0;
// 	while (low <= high) {
// 		mid = (high + low) / 2;
// 		int value = arr[mid];
// 		int correctIndex = value - 1;
// 		diff = correctIndex - mid;
// 		// diff is number of missing elements
// 		if (diff >= k) {
// 			high = mid - 1;
// 		} else if (diff < k) {
// 			low = mid + 1;
// 		}
// 	}
// 	int sum = diff;
// 	int idx = mid;
// 	if (sum >= k && idx != 0) {
// 		sum -= (arr[idx] - arr[idx - 1] - 1);
// 		idx--;
// 	} else if (idx == 0 && k < arr[0]) {
// 		return k;
// 	}
// 	return arr[idx] + k - sum;
// }

int findKthPositive(vector<int> &arr, int k) {
	//
	int low = 0;
	int high = arr.size();
	int diff = 0;
	int mid = 0;
	while (low < high) {
		mid = (high + low) / 2;
		int value = arr[mid];
		int correctIndex = value - 1;
		diff = correctIndex - mid;
		// diff is number of missing elements
		if (diff >= k) {
			high = mid;
		} else if (diff < k) {
			low = mid + 1;
		}
	}

	int right;
	if (high == arr.size()) {
		right = arr[arr.size() - 1] + 1;
	} else {
		right = arr[high];
	}

	return (right) - (right - 1 - high - k) - 1;
}

int main() {
	//
	int k;
	vector<int> arr;

	// k = 5;
	// arr = {2, 3, 4, 7, 11};
	k = 2;
	arr = {1, 2, 3, 4};
	// k = 2;
	// arr = {3, 10};
	// k = 12;
	// arr = {1, 10, 21, 22, 25};
	// k = 1;
	// arr = {1, 3};
	// k = 1;
	// arr = {1};
	// k = 1;
	// arr = {2};
	// k = 4;
	// arr = {7, 13, 21, 25, 29, 32, 38, 45};
	// k = 96;
	// arr = {6,		7,	 10,	20,	28,	29,	33,	37,	39,	40,	49,	53,	55,	72,
	// 			 75,	76,	85,	87,	88,	94,	106, 107, 119, 120, 129, 142, 147, 152,
	// 			 157, 159, 161, 173, 178, 183, 187, 188, 193, 199, 202, 212, 215, 224,
	// 			 227, 230, 237, 239, 246, 251, 256, 260, 266, 268, 273, 277, 279, 281,
	// 			 291, 297, 298, 310, 312, 314, 315, 321, 324, 326, 329, 341, 342, 348,
	// 			 355, 367, 370, 374, 387, 389, 394, 413, 420, 424, 429, 446, 447, 458,
	// 			 460, 464, 467, 473, 477, 478, 498, 500, 501, 503, 514, 515, 523, 525,
	// 			 528, 529, 531, 535, 539, 555, 566, 569, 572, 583, 588, 591, 596, 602,
	// 			 604, 605, 606, 610, 611, 616, 619, 622, 623, 631, 632, 640, 642, 645,
	// 			 647, 661, 680, 684, 685, 687, 694, 696, 698, 714, 717, 720, 726, 734,
	// 			 738, 742, 745, 753, 770, 775, 780, 781, 783, 787, 788, 798, 806, 821,
	// 			 835, 852, 865, 873, 888, 897, 926, 932, 935, 939, 945, 956, 966, 967,
	// 			 969, 973, 979, 980, 986, 992, 995, 997};

	int res = findKthPositive(arr, k);

	cout << res << endl;

	return 0;
}