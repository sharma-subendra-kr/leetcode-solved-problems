// 929. Unique Email Addresses
// https://leetcode.com/problems/unique-email-addresses/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

#include "../../../utils/customString.h"

// int numUniqueEmails(vector<string> &emails) {
// 	unordered_set<string> emailSet;
// 	int sum = 0;

// 	for (int i = 0; i < emails.size(); i++) {
// 		string temp1;
// 		string temp2;
// 		vector<string> words;

// 		vector<string> w = split(emails[i], '@');
// 		string temp = w[0];

// 		temp1 = split(temp, '+')[0];

// 		words = split(temp1, '.');
// 		temp2 = "";
// 		for (string word : words) {
// 			temp2 += word;
// 		}

// 		temp2 = temp2 + "@" + w[1];

// 		auto iter = emailSet.find(temp2);
// 		if (iter == emailSet.end()) {
// 			emailSet.insert(temp2);
// 			sum++;
// 		}
// 	}

// 	return sum;
// }

int numUniqueEmails(vector<string> &emails) {
	unordered_set<string> emailSet;
	int sum = 0;

	for (int i = 0; i < emails.size(); i++) {
		string cleanEmail = "";
		for (char c : emails[i]) {
			if (c == '+' || c == '@') {
				break;
			} else if (c == '.') {
				continue;
			}
			cleanEmail += c;
		}

		emailSet.insert(cleanEmail +
										emails[i].substr(emails[i].find('@'), string::npos));
	}

	return emailSet.size();
}

int main() {
	//

	vector<string> emails;

	emails = {"test.email+alex@leetcode.com",
						"test.e.mail+bob.cathy@leetcode.com",
						"testemail+david@lee.tcode.com"};

	// emails = {"test.email+alex@leetcode.com", "test.email.leet+alex@code.com"};

	int res = numUniqueEmails(emails);

	cout << res << endl;

	return 0;
}