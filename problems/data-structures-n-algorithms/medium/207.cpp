// 207. Course Schedule
// https://leetcode.com/problems/course-schedule/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

int dfs(unordered_map<int, forward_list<int>> &graph, int current,
				int visited[], int cache[]) {
	if (visited[current] == 1)
		return 0;

	visited[current] = 1;

	auto iter = graph.find(current);
	if (iter == graph.end()) {
		return 1;
	}

	for (auto i = iter->second.begin(); i != iter->second.end(); i++) {
		if (cache[*i] != -1) {
			return cache[*i];
		}
		bool res = dfs(graph, *i, visited, cache);
		cache[*i] = res;
		if (res == 0)
			return 0;
	}
	return 1;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
	unordered_map<int, forward_list<int>> graph;

	for (int i = 0; i < prerequisites.size(); i++) {
		vector<int> v = prerequisites[i];
		auto iter = graph.find(v[1]);
		if (iter == graph.end()) {
			forward_list<int> fl;
			fl.push_front(v[0]);
			graph.insert({v[1], fl});
		} else {
			iter->second.push_front(v[0]);
		}
	}

	int cache[numCourses];
	for (int i = 0; i < numCourses; i++)
		cache[i] = -1;

	for (auto iter = graph.begin(); iter != graph.end(); iter++) {
		int *visited = new int[numCourses];
		int current = iter->first;
		int res = dfs(graph, current, visited, cache);
		delete[] visited;
		if (res == 0)
			return false;
	}

	return true;
}

int main() {
	int numCourses;
	vector<vector<int>> prerequisites;

	numCourses = 2;
	prerequisites = {{1, 0}};

	bool res = canFinish(numCourses, prerequisites);

	cout << res << endl;

	return 0;
}