// 359. Logger Rate Limiter
// https://leetcode.com/problems/logger-rate-limiter/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <string>

using namespace std;

class Logger {
private:
	unordered_map<string, int> mp;

public:
	/** Initialize your data structure here. */
	Logger() {
		//
	}

	/** Returns true if the message should be printed in the given timestamp,
		 otherwise returns false. If this method returns false, the message will not
		 be printed. The timestamp is in seconds granularity. */
	bool shouldPrintMessage(int timestamp, string message) {
		auto iter = mp.find(message);
		if (iter != mp.end()) {
			if (timestamp - iter->second > 10) {
				iter->second = timestamp;
				return true;
			} else {
				return false;
			}
		}
		mp.insert({message, timestamp});
		return true;
	}
};

int main() {
	//

	return 0;
}