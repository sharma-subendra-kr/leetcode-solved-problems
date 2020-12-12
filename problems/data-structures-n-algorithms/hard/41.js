// 41. First Missing Positive
// https://leetcode.com/problems/first-missing-positive/

const firstMissingPositive = function (nums) {
	const len = nums.length;

	for (let i = 0; i < len; i++) {
		if (nums[i] <= 0 || nums[i] > len) {
			nums[i] = len + 1;
		}
	}

	for (let i = 0; i < len; i++) {
		let num = Math.abs(nums[i]);
		if (num > len) {
			continue;
		}

		num--;
		if (nums[num] > 0) {
			nums[num] = -1 * nums[num];
		}
	}

	for (let i = 0; i < len; i++) {
		if (nums[i] > 0) {
			return i + 1;
		}
	}

	return len + 1;
};

function main() {
	debugger;
	// const res = firstMissingPositive([1, 2, 0]);
	// const res = firstMissingPositive([3,4,-1,1]);
	const res = firstMissingPositive([7, 8, 9, 11, 12]);

	console.log(res);
}

main();
