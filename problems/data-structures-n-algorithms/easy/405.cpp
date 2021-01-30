// 405. Convert a Number to Hexadecimal
// https://leetcode.com/problems/convert-a-number-to-hexadecimal/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

// string toHex(int num) {
// 	if (num == 0) {
// 		return "0";
// 	}

// 	vector<char> arr;
// 	char mp[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
// 								 '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

// 	int count = 0;
// 	while (count < 32) {
// 		int count16 = 0;
// 		int n = 0;
// 		while (count16 != 4) {
// 			int bit = num % 2 == 0 ? 0 : 1;
// 			num >>= 1;
// 			n = n += (pow(2, count16) * bit);
// 			count16++;
// 		}
// 		count += 4;
// 		arr.push_back(mp[n]);
// 	}

// 	int i = arr.size() - 1;

// 	while (arr[i] == '0') {
// 		arr.pop_back();
// 		i--;
// 	}

// 	reverse(arr.begin(), arr.end());

// 	string res(arr.begin(), arr.end());

// 	return res;
// }

string toHex(int num) {
	if (num == 0) {
		return "0";
	}

	unsigned int _num = num;

	string res;
	char mp[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
								 '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	while (_num != 0) {
		res = mp[(_num & 15)] + res;
		_num >>= 4;
	}

	return res;
}

int main() {
	int num;

	// num = 26;
	num = -1;

	string res = toHex(num);

	cout << res << endl;

	return 0;
}