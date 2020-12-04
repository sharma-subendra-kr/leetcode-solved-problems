// 169. Majority Element
// https://leetcode.com/problems/majority-element/

// Boyer–Moore majority vote algorithm
const majorityElement = function (nums) {
	let x;
	let c = 0;

	for (const item of nums) {
		if (c === 0) {
			x = item;
			c++;
		} else if (x === item) {
			c++;
		} else {
			c--;
		}
	}

	return x;
};

function main() {
	// const res = majorityElement([3, 2, 3]);
	const res = majorityElement([2, 2, 1, 1, 1, 2, 2]);
	console.log(res);
}

main();
