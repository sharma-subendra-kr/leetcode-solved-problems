// 34. Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// const binarySearch = function (nums, target, direction) {
// 	let low = 0;
// 	let high = nums.length - 1;
// 	let mid;
// 	let index = -1;

// 	while (low <= high) {
// 		mid = Math.floor((high + low) / 2);

// 		if (nums[mid] === target) {
// 			index = mid;
// 			if (direction === "left") {
// 				high = mid - 1;
// 			} else {
// 				low = mid + 1;
// 			}
// 		} else if (nums[mid] > target) {
// 			high = mid - 1;
// 		} else {
// 			low = mid + 1;
// 		}
// 	}

// 	return index;
// };

const binarySearch = function (nums, target) {
	let low = 0;
	let high = nums.length - 1;
	let mid;
	const res = [-1, -1];

	while (low < high) {
		mid = Math.floor((low + high) / 2);
		if (nums[mid] < target) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	if (nums[low] === target) {
		res[0] = low;
	}

	low = 0;
	high = nums.length - 1;

	while (low < high) {
		mid = Math.floor((low + high) / 2) + 1;
		if (nums[mid] > target) {
			high = mid - 1;
		} else {
			low = mid;
		}
	}
	if (nums[low] === target) {
		res[1] = low;
	}

	return res;
};

const searchRange = function (nums, target) {
	return binarySearch(nums, target);
};

function main() {
	debugger;
	// const res = searchRange([5, 7, 7, 8, 8, 10], 8);
	const res = searchRange([10], 8);
	console.log(res);
}

main();
