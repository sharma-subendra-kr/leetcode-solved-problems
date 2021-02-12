// 346. Moving Average from Data Stream
// https://leetcode.com/problems/moving-average-from-data-stream/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

class MovingAverage {
private:
	queue<int> q;
	int size;
	int sum;
	int count;

public:
	/** Initialize your data structure here. */
	MovingAverage(int size) {
		this->size = size;
		sum = 0;
		count = 0;
	}

	double next(int val) {
		if (this->count == size) {
			int front = q.front();
			q.pop();
			sum -= front;
			q.push(val);
			sum += val;
		} else {
			q.push(val);
			sum += val;
			count++;
		}

		return (double)sum / (double)count;
	}
};

int main() {
	//

	MovingAverage *ma = new MovingAverage(3);

	cout << ma->next(1) << endl;
	cout << ma->next(10) << endl;
	cout << ma->next(3) << endl;
	cout << ma->next(5) << endl;

	return 0;
}