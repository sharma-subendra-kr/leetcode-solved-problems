// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/

const maxArea = function (height) {
	let left = 0;
	let right = height.length - 1;

	let lh = 0;
	let rh = 0;

	let max = 0;

	while (left < right) {
		lh = height[left];
		rh = height[right];

		const width = right - left;

		const h = Math.min(lh, rh);

		const area = h * width;

		if (area > max) {
			max = area;
		}

		if (lh < rh) {
			left++;
		} else {
			right--;
		}
	}

	return max;
};

function main() {
	debugger;
	// const res = maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]);
	const res = maxArea([1, 6, 5, 2, 4, 2, 6, 2, 5]);
	console.log(res);
}

main();
