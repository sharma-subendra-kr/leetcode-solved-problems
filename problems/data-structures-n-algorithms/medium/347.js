// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

// Quickselect Algo
// const swap = function (arr, a, b) {
// 	const temp = arr[a];
// 	arr[a] = arr[b];
// 	arr[b] = temp;
// };

// const topKFrequent = function (nums, k) {
// 	const map = {};
// 	for (let i = 0; i < nums.length; i++) {
// 		if (!map[nums[i]]) {
// 			map[nums[i]] = 1;
// 		} else {
// 			map[nums[i]]++;
// 		}
// 	}

// 	const kArr = Object.keys(map);

// 	let _k = k;
// 	let pivot;
// 	const res = [];

// 	while (_k > 0) {
// 		pivot = kArr.length - (k - _k) - 1;

// 		let mark = 0;
// 		let iter = 0;

// 		while (iter <= pivot) {
// 			const markNum = map[kArr[mark]];
// 			let iterNum = map[kArr[iter]];
// 			const pivotNum = map[kArr[pivot]];

// 			if (iterNum < markNum) {
// 				swap(kArr, iter, mark);
// 				iterNum = markNum;
// 			}

// 			if (iterNum > pivotNum) {
// 				mark = iter;
// 			}
// 			iter++;
// 		}
// 		res.push(kArr[pivot]);
// 		_k--;
// 	}

// 	return res;
// };

// Bucket sort
const topKFrequent = function (nums, k) {
	const map = {};
	for (let i = 0; i < nums.length; i++) {
		if (!map[nums[i]]) {
			map[nums[i]] = 1;
		} else {
			map[nums[i]]++;
		}
	}

	const kArr = Object.keys(map);

	const res = [];

	kArr.sort((a, b) => {
		return map[a] - map[b];
	});

	let _k = kArr.length - 1;
	while (k !== 0) {
		res.push(kArr[_k]);
		_k--;
		k--;
	}

	return res;
};

// Write heap solution also

function main() {
	debugger;
	const res = topKFrequent([1, 1, 1, 2, 2, 3], 2);
	// const res = topKFrequent([1], 1);
	console.log(res);
}

main();
