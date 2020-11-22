// 46. Permutations
// https://leetcode.com/problems/permutations/

function swap(arr, i, j) {
	let temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

var _permute = function (res, nums, i) {
	if (i === nums.length - 1) {
		res.push([...nums]);
		return;
	}
	for (let j = i; j < nums.length; j++) {
		swap(nums, i, j);
		_permute(res, [...nums], i + 1);
	}
};

var permute = function (nums) {
	const res = [];

	_permute(res, nums, 0);

	return res;
};

function main() {
	var arr = permute([1, 2]);

	console.log(arr);
}

main();
