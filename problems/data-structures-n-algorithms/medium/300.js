// 300. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/

// const lengthOfLIS = function (nums) {
// 	const len = nums.length;
// 	const arr = new Array(len);

// 	let finalMax = 0;
// 	for (let i = len - 1; i >= 0; i--) {
// 		const item = nums[i];
// 		let max = 0;
// 		for (let j = i + 1; j < len; j++) {
// 			if (item < nums[j] && arr[j] > max) {
// 				max = arr[j];
// 			}
// 		}
// 		arr[i] = max + 1;
// 		if (finalMax < arr[i]) {
// 			finalMax = arr[i];
// 		}
// 	}

// 	return finalMax;
// };

const binarySearch = function (arr, start, len, val) {
	let low = start;
	let high = len - 1;

	let res = 0;

	while (low <= high) {
		const mid = Math.floor((low + high) / 2);

		res = mid;
		if (arr[mid] === val) {
			break;
		} else if (arr[mid] < val) {
			res++;
		}

		if (arr[mid] > val) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	return res;
};

const lengthOfLIS = function (nums) {
	const dp = new Array(nums.length);

	let len = 0;
	for (const item of nums) {
		const i = binarySearch(dp, 0, len, item);

		dp[i] = item;
		if (i === len) {
			len++;
		}
	}

	return len;
};

function main() {
	debugger;
	// const res = lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18]);
	// const res = lengthOfLIS([0, 1, 0, 3, 2, 3]);
	// const res = lengthOfLIS([7, 7, 7, 7, 7, 7, 7]);
	const res = lengthOfLIS([1, 3, 2]);

	console.log(res);
}

main();
