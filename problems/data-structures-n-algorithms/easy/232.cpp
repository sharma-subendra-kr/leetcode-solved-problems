// 232. Implement Queue using Stacks
// https://leetcode.com/problems/implement-queue-using-stacks/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <stack>

using namespace std;

class MyQueue {
private:
	stack<int> st1;
	stack<int> st2;

public:
	/** Initialize your data structure here. */
	MyQueue() {}

	/** Push element x to the back of queue. */
	void push(int x) {
		//
		int count = st1.size();
		while (count != 0) {
			int top = st1.top();
			st1.pop();
			st2.push(top);
			count--;
		}
		st1.push(x);
		while (!st2.empty()) {
			int top = st2.top();
			st2.pop();
			st1.push(top);
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int front = st1.top();
		st1.pop();
		return front;
	}

	/** Get the front element. */
	int peek() {
		//
		return st1.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		//
		return st1.empty() ? true : false;
	}
};

int main() {
	MyQueue *q = new MyQueue();

	q->push(1);

	return 0;
}