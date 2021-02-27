// 399. Evaluate Division
// https://leetcode.com/problems/evaluate-division/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

double getProduct(string numeKey, string denomKey, string currentKey,
									double product,
									unordered_map<string, unordered_map<string, double>> ump,
									unordered_map<string, bool> visited) {
	if (currentKey == numeKey) {
		return product;
	}

	auto iterFind = ump.find(currentKey != "" ? currentKey : denomKey);
	if (iterFind == ump.end()) {
		return 0;
	}

	unordered_map<string, double> insideUmp = iterFind->second;
	for (auto iter = insideUmp.begin(); iter != insideUmp.end(); iter++) {
		if (visited.find(iter->first) != visited.end()) {
			continue;
		}
		visited[iter->first] = true;
		double res = getProduct(numeKey, denomKey, iter->first,
														iter->second * product, ump, visited);
		visited[iter->first] = false;
		if (res != 0) {
			return res;
		}
	}

	return 0;
}

vector<double> calcEquation(vector<vector<string>> &equations,
														vector<double> &values,
														vector<vector<string>> &queries) {
	//
	unordered_map<string, unordered_map<string, double>> ump;

	for (int i = 0; i < equations.size(); i++) {
		auto iter = ump.find(equations[i][0]);
		if (iter != ump.end()) {
			iter->second.insert({equations[i][1], values[i]});
		} else {
			unordered_map<string, double> temp;
			temp.insert({equations[i][1], values[i]});
			ump.insert({equations[i][0], temp});
		}
		iter = ump.find(equations[i][1]);
		if (iter != ump.end()) {
			iter->second.insert({equations[i][0], 1 / values[i]});
		} else {
			unordered_map<string, double> temp;
			temp.insert({equations[i][0], 1 / values[i]});
			ump.insert({equations[i][1], temp});
		}
	}

	vector<double> res;
	for (int i = 0; i < queries.size(); i++) {
		auto iter = ump.find(queries[i][0]);
		auto iter1 = ump.find(queries[i][1]);
		bool flag = false;

		if (iter == ump.end() || iter1 == ump.end()) {
			res.push_back(-1);
			continue;
		}

		unordered_map<string, bool> visited;
		double result = getProduct(iter->first, queries[i][1], "", 1, ump, visited);
		if (result != 0) {
			res.push_back(1 / result);
		} else {
			res.push_back(-1);
		}
	}

	return res;
}

int main() {
	//
	vector<vector<string>> equations;
	vector<double> values;
	vector<vector<string>> queries;

	// equations = {{"a", "b"}, {"b", "c"}};
	// values = {2.0, 3.0};
	// queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

	equations = {{"x1", "x2"}, {"x2", "x3"}, {"x3", "x4"}, {"x4", "x5"}};
	values = {3.0, 4.0, 5.0, 6.0};
	queries = {{"x1", "x5"}, {"x5", "x2"}, {"x2", "x4"},
						 {"x2", "x2"}, {"x2", "x9"}, {"x9", "x9"}};

	vector<double> res = calcEquation(equations, values, queries);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}