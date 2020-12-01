// 55. Jump Game
// https://leetcode.com/problems/jump-game/

// DP recursive
// let memo = {};

// const getMemo = function (i) {
// 	if (memo[i]) {
// 		return memo[i];
// 	}
// 	return false;
// };

// const setMemo = function (i, val) {
// 	memo[i] = val;
// };

// const step = function (i, nums) {
// 	if (i === nums.length - 1) {
// 		return true;
// 	}

// 	let res = false;
// 	let cnt = i;

// 	for (let j = 0; j < nums[i]; j++) {
// 		let temp = getMemo(cnt + 1);
// 		if (!temp) {
// 			temp = step(++cnt, nums);
// 			setMemo(cnt, temp);
// 		}
// 		res = res || temp;
// 	}

// 	return res;
// };

// const canJump = function (nums) {
// 	memo = {};
// 	return step(0, nums);
// };

// DP matrix
// const canJump = function (nums) {
// 	if (nums.length === 1) {
// 		return true;
// 	}

// 	const matrix = new Array(nums.length);
// 	for (let i = 0; i < nums.length; i++) {
// 		matrix[i] = new Array(nums.length);
// 	}

// 	for (let i = 0; i < nums.length - 1; i++) {
// 		for (let j = 0; j < nums.length; j++) {
// 			matrix[i][j] = 0;
// 		}
// 	}

// 	for (let i = 1; i <= nums[0]; i++) {
// 		matrix[0][i] = 1;
// 		matrix[i][i] = 1;

// 		if (i === nums.length - 1) {
// 			return true;
// 		}
// 	}

// 	for (let i = 0; i < nums.length - 1; i++) {
// 		for (let j = i + 1; j <= Math.min(i + nums[i], nums.length - 1); j++) {
// 			if (matrix[i][i] === 0) {
// 				break;
// 			}
// 			matrix[i][j] = 1;
// 			matrix[j][j] = 1;

// 			if (j === nums.length - 1) {
// 				return true;
// 			}
// 		}
// 	}

// 	return false;
// };

// DP one pass
// const canJump = function (nums) {
// 	const len = nums.length;
// 	if (len === 1) {
// 		return true;
// 	}

// 	let max = -1;
// 	for (let i = 0; i < len; i++) {
// 		if (i + nums[i] > max) {
// 			max = i + nums[i];
// 		}
// 		if (nums[i] === 0 && max <= i && i !== len - 1) {
// 			return false;
// 		}
// 	}
// 	return true;
// };

// DP one pass
const canJump = function (nums) {
	const len = nums.length;

	let lastIndex = len - 1;
	for (let i = lastIndex; i >= 0; i--) {
		if (i + nums[i] >= lastIndex) {
			lastIndex = i;
		}
	}
	return lastIndex === 0;
};

function main() {
	// const res = canJump([2, 3, 1, 1, 4]);
	// const res = canJump([3, 2, 1, 0, 4]);
	// const res = canJump([0, 1]);
	// const res = canJump([2, 0, 0]);
	const res = canJump([5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0]);

	console.log(res);
}

main();
