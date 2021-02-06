// 443. String Compression
// https://leetcode.com/problems/string-compression/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

// int compress(vector<char> &chars) {
// 	//
// 	int count = 1;
// 	int currCount = 1;
// 	int start = 0;

// 	for (int i = 1; i < chars.size(); i++) {
// 		if (chars[i - 1] != chars[i] || count == 10) {
// 			if (count == 1) {
// 				chars[start + 1] = chars[i];
// 			} else if (currCount == 10 && chars[i - 1] != chars[i]) {
// 				chars[i] = chars[i];
// 			}

// 			start = i;
// 			count = 1;
// 			continue;
// 		}
// 	}
// }

vector<char> getCountChars(int count) {
	vector<char> res;

	while (count != 0) {
		char i = (char)((count % 10) + 48);
		res.push_back(i);
		count /= 10;
	}

	reverse(res.begin(), res.end());
	return res;
}

int compress(vector<char> &chars) {
	int iter = 0;
	int start = iter;
	char curr = chars[start];

	while (iter < chars.size()) {
		int initIter = iter;
		while (iter < chars.size() && chars[iter] == curr) {
			iter++;
		}
		if (iter < chars.size()) {
			curr = chars[iter];
		}
		vector<char> res = getCountChars(iter - initIter);
		int count = 0;

		while (count < res.size() && iter - initIter > 1) {
			chars[++start] = res[count];
			count++;
		}

		++start;
		if (start < chars.size()) {
			chars[start] = curr;
		}
	}

	return start;
}

int main() {
	//
	vector<char> chars;

	// chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
	// chars = {'a'};
	// chars = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
	// 				 'a', 'a', 'a', 'a', 'a', 'b', 'b', 'b'};
	chars = {'a', 'a', 'a', 'b', 'b', 'a', 'a'};

	int res = compress(chars);

	cout << res << endl;

	for (int i = 0; i < chars.size(); i++) {
		cout << chars[i] << endl;
	}

	return 0;
}