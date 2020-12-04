// 238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/

const productExceptSelf = function (nums) {
	const res = new Array(nums.length);
	let prod = 1;

	for (let i = 0; i < nums.length; i++) {
		const temp = nums[i];
		res[i] = prod;
		prod *= temp;
	}

	prod = 1;
	for (let i = nums.length - 1; i >= 0; i--) {
		res[i] *= prod;
		prod *= nums[i];
	}

	return res;
};

function main() {
	// const res = productExceptSelf([1, 2, 3, 4]);
	const res = productExceptSelf([2, 3, 4, 5]);
	console.log(res);
}

main();
