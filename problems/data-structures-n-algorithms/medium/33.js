// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

// const getPeakIndex = function (nums, l, h) {
// 	const low = l;
// 	const high = h;

// 	if (low > high) {
// 		return -1;
// 	}

// 	const mid = Math.floor((high + low) / 2);

// 	if (nums[mid] > nums[mid + 1]) {
// 		return mid;
// 	}
// 	const v1 = getPeakIndex(nums, low, mid - 1);
// 	const v2 = getPeakIndex(nums, mid + 1, high);

// 	return (nums[v1] || -2147483648) > (nums[v2] || -2147483648) ? v1 : v2;
// };

const getMinIndex = function (nums, l, h) {
	let low = l;
	let high = h;
	let mid;

	while (low < high) {
		mid = Math.floor((low + high) / 2);

		if (nums[mid] > nums[high]) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}

	return low;
};

const binarySearch = function (nums, target, l, h) {
	let low = l;
	let high = h;
	let mid;

	while (low <= high) {
		mid = Math.floor((low + high) / 2);
		if (nums[mid] === target) {
			return mid;
		} else if (nums[mid] > target) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
};

const search = function (nums, target) {
	const min = getMinIndex(nums, 0, nums.length - 1);

	let res;
	if (target >= nums[min] && target <= nums[nums.length - 1]) {
		// search in left part
		res = binarySearch(nums, target, min, nums.length - 1);
	} else {
		// search in right part
		res = binarySearch(nums, target, 0, min - 1);
	}

	return !isNaN(res) ? res : -1;
};

function main() {
	debugger;
	const res = search([4, 5, 6, 7, 0, 1, 2], 0);
	// const res = search([5, 6, 7, 0, 1, 2, 4], 0);
	// const res = search([1, 3], 3);
	// const res = search([1], 1);
	console.log(res);
}

main();
