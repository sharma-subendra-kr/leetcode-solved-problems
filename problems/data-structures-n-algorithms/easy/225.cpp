// 225. Implement Stack using Queues
// https://leetcode.com/problems/implement-stack-using-queues/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <stack>

using namespace std;

class MyStack {
private:
	queue<int> qu;

public:
	/** Initialize your data structure here. */
	MyStack() {}

	/** Push element x onto stack. */
	void push(int x) {
		//
		qu.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int count = qu.size() - 1;
		while (count != 0) {
			int front = qu.front();
			qu.pop();
			qu.push(front);
			count--;
		}
		int top = qu.front();
		qu.pop();
		return top;
	}

	/** Get the top element. */
	int top() {
		//
		return qu.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() { return qu.size() > 0 ? false : true; }
};

int main() {
	MyStack *s = new MyStack();

	s->push(1);

	return 0;
}