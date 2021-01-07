// 210. Course Schedule II
// https://leetcode.com/problems/course-schedule-ii/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <forward_list>
#include <queue>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
	unordered_map<int, vector<int>> graph;

	for (int i = 0; i < prerequisites.size(); i++) {
		vector<int> v = prerequisites[i];
		auto iter = graph.find(v[1]);
		if (iter == graph.end()) {
			vector<int> lst;
			lst.push_back(v[0]);
			graph.insert({v[1], lst});
		} else {
			iter->second.push_back(v[0]);
		}
	}

	queue<int> _queue;
	int *indegree = new int[numCourses]{0};
	for (int i = 0; i < numCourses; i++) {
		auto iter = graph.find(i);
		if (iter != graph.end()) {
			for (int j = 0; j < iter->second.size(); j++) {
				indegree[iter->second[j]]++;
			}
		}
	}

	for (int i = 0; i < numCourses; i++) {
		if (indegree[i] == 0) {
			_queue.push(i);
		}
	}

	vector<int> result;

	int *visited = new int[numCourses]{0};
	while (!_queue.empty()) {
		int front = _queue.front();
		_queue.pop();

		if (visited[front] == 1)
			return vector<int>();

		visited[front] = 1;
		result.push_back(front);

		auto iter = graph.find(front);

		if (iter != graph.end()) {
			for (int i = 0; i < iter->second.size(); i++) {
				if (indegree[iter->second[i]] - 1 == 0) {
					_queue.push(iter->second[i]);
					indegree[iter->second[i]]--;
					continue;
				}
				indegree[iter->second[i]]--;
			}
		}
	}

	if (result.size() == numCourses) {
		return result;
	}

	return vector<int>();
}

int main() {
	int numCourses;
	vector<vector<int>> prerequisites;

	// numCourses = 1;
	// prerequisites = {};
	// numCourses = 2;
	// prerequisites = {};
	// numCourses = 2;
	// prerequisites = {{1, 0}};
	// numCourses = 4;
	// prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
	numCourses = 3;
	prerequisites = {{1, 0}, {1, 2}, {0, 1}};

	vector<int> res = findOrder(numCourses, prerequisites);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}