// 301. Remove Invalid Parentheses
// https://leetcode.com/problems/remove-invalid-parentheses/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool isValid(string s) {
	int left = 0, right = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			left++;
		} else if (s[i] == ')') {
			if (left == right) {
				return false;
			}
			right++;
		}
	}

	return left == right;
}

vector<string> removeInvalidParentheses(string s) {
	vector<string> res;
	unordered_set<string> sres;
	queue<string> q;
	unordered_set<string> visited;
	int len = -1;

	q.push(s);
	visited.insert(s);

	if (isValid(s)) {
		sres.insert(s);
	}

	while (!q.empty()) {
		string str = q.front();
		q.pop();

		if (isValid(str) && (str.size() == len || len == -1)) {
			sres.insert(str);
			if (len == -1) {
				len = str.size();
			}
			continue;
		}

		for (int i = 0; i < str.size(); i++) {
			if (str[i] != '(' && str[i] != ')') {
				continue;
			}

			string temp = str.substr(0, i) + str.substr(i + 1);
			if (visited.find(temp) == visited.end()) {
				q.push(temp);
				visited.insert(temp);
			}
		}
	}

	res.assign(sres.begin(), sres.end());
	return res;
}

int main() {
	string s;

	s = "()())()";

	vector<string> res = removeInvalidParentheses(s);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ", " << endl;
	}

	return 0;
}