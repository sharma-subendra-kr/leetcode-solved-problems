// 690. Employee Importance
// https://leetcode.com/problems/employee-importance/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

class Employee {
public:
	int id;
	int importance;
	vector<int> subordinates;
};

class Solution {
public:
	void getSubordinates(Employee *employee, stack<Employee *> &st,
											 unordered_map<int, Employee *> &ump) {
		for (int i = 0; i < employee->subordinates.size(); i++) {
			st.push(ump.find(employee->subordinates[i])->second);
		}
	}

	int getImportance(vector<Employee *> employees, int id) {
		unordered_map<int, Employee *> ump;
		stack<Employee *> st;

		int sum = 0;

		for (int i = 0; i < employees.size(); i++) {
			ump.insert({employees[i]->id, employees[i]});
			if (employees[i]->id == id) {
				st.push(employees[i]);
			}
		}

		while (!st.empty()) {
			Employee *top = st.top();
			st.pop();

			sum += top->importance;
			getSubordinates(top, st, ump);
			ump.erase(top->id);
		}

		return sum;
	}
};

int main() {
	//

	Employee *e1 = new Employee();
	e1->id = 1;
	e1->importance = 5;
	e1->subordinates = vector<int>{2, 3};
	Employee *e2 = new Employee();
	e2->id = 2;
	e2->importance = 3;
	e2->subordinates = vector<int>{};
	Employee *e3 = new Employee();
	e3->id = 3;
	e3->importance = 3;
	e3->subordinates = vector<int>{};

	vector<Employee *> employees({e1, e2, e3});

	Solution *sln = new Solution();
	int res = sln->getImportance(employees, 1);

	cout << res << endl;

	return 0;
}