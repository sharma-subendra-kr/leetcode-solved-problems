// 78. Subsets
// https://leetcode.com/problems/subsets/

const _subsets = function (res, nums, arr, j) {
	if (j === nums.length) {
		return;
	}
	for (let i = j; i < nums.length; i++) {
		const temp = [...arr, nums[i]];
		res.push(temp);
		_subsets(res, nums, temp, i + 1);
	}
};

const subsets = function (nums) {
	const res = [];
	if (nums.length === 0) {
		return res;
	}

	res.push([]);
	_subsets(res, nums, [], 0);

	return res;
};

function main() {
	debugger;
	const arr = subsets([]);

	console.log(arr);
}

main();
