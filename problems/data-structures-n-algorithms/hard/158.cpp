// 158. Read N Characters Given Read4 II - Call multiple times
// https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

// class Solution {
// private:
//     int iter = 0;
//     int ptr = 0;
//     int bptr = 0;
//     int res = 0;
//     char *buf4 = new char[4];

// public:
//     /**
//      * @param buf Destination buffer
//      * @param n   Number of characters to read
//      * @return    The number of actual characters read
//      */

//     int read(char *buf, int n) {
//         if (iter + n <= ptr && iter != ptr) {
//             for (int i = 0; i < n; i++) {
//                 buf[iter + i] = buf4[bptr++];
//             }

//             iter += n;
//             return n;
//         } else if (iter + n > ptr && iter != ptr) {
//             for (int i = 0; i < ptr - iter; i++) {
//                 buf[iter + i] = buf4[bptr++];
//             }
//             iter += (ptr - iter);
//             n = iter + n - ptr;
//         }

//         int rd = read4(buf4);
//         ptr += rd;

//         bptr = 0;
//         while (bptr != n && rd != 0) {
//             buf[iter++] = buf4[bptr++];
//         }

//         return n;
//     }
// };

class Solution {
private:
	int iter = 0;
	int ptr = 0;
	int bptr = 0;

	char *buf4 = new char[4];

public:
	/**
	 * @param buf Destination buffer
	 * @param n   Number of characters to read
	 * @return    The number of actual characters read
	 */

	int read(char *buf, int n) {
		int curr = 0;
		while (curr < n) {
			if (iter == ptr) {
				int rd = read4(buf4);
				bptr = 0;
				ptr += rd;
				if (rd == 0) {
					return curr;
				}
			}

			while (curr < n && iter < ptr && bptr < 4) {
				buf[curr++] = buf4[bptr++];
				iter++;
			}
		}
		return curr;
	}
};

int read(char *buf, int n) {}

int main() {
	//
	return 0;
}