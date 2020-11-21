// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

vector<list<string>> dfs(string digits, int digitsIndex,
												 map<string, string> &dToStr) {
	int i;
	vector<list<string>> res;

	string t = digits.substr(digitsIndex, 1);
	auto mIter = dToStr.find(t);
	if (mIter == dToStr.end()) {
		return res;
	}
	string buttonStr = mIter->second;

	for (i = 0; i < buttonStr.size(); i++) {
		string str;
		str.append(buttonStr.substr(i, 1));
		vector<list<string>> temp = dfs(digits, digitsIndex + 1, dToStr);
		if (temp.size() == 0) {
			list<string> tempList;
			tempList.push_front(str);
			res.push_back(tempList);
		} else {
			for (int iter = 0; iter < temp.size(); iter++) {
				temp[iter].push_front(str);
				res.push_back(temp[iter]);
			}
		}
	}

	return res;
}

vector<string> letterCombinations(string digits) {
	map<string, string> dToStr;
	dToStr["2"] = "abc";
	dToStr["3"] = "def";
	dToStr["4"] = "ghi";
	dToStr["5"] = "jkl";
	dToStr["6"] = "mno";
	dToStr["7"] = "pqrs";
	dToStr["8"] = "tuv";
	dToStr["9"] = "wxyz";

	vector<string> result;
	vector<list<string>> res = dfs(digits, 0, dToStr);
	for (int i = 0; i < res.size(); i++) {
		string temp(res[i].size(), '-');
		int count = 0;
		for (auto iter = res[i].begin(); iter != res[i].end(); iter++) {
			temp.replace(count++, 1, *iter);
		}
		result.push_back(temp);
	}

	return result;
}

int main() {
	string digits;
	vector<string> res;

	cin >> digits;

	res = letterCombinations(digits);

	for (auto iter = 0; iter < res.size(); iter++) {
		cout << res[iter] << " ";
	}
}