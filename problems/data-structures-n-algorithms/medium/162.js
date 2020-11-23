// 162. Find Peak Element
// https://leetcode.com/problems/find-peak-element/

const findPeakElement = function (nums) {
	if (nums.length <= 1) {
		return 0;
	}

	let low = 0;
	let high = nums.length - 1;
	let mid;

	while (low <= high) {
		mid = Math.floor((high + low) / 2);

		if (
			nums[mid] > (nums[mid + 1] || Number.MIN_SAFE_INTEGER) &&
			nums[mid] > (nums[mid - 1] || Number.MIN_SAFE_INTEGER)
		) {
			return mid;
		} else if (nums[mid] > nums[mid - 1]) {
			low = mid + 1;
		} else if (nums[mid] > nums[mid + 1]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
};

function main() {
	debugger;
	// const res = findPeakElement([1, 2, 1, 3, 5, 6, 4]);
	// const res = findPeakElement([1, 2, 3, 1]);
	// const res = findPeakElement([1, 2]);
	// const res = findPeakElement([-2147483647, -2147483648]);
	const res = findPeakElement([-2147483648, -2147483647]);

	console.log(res);
}

main();
