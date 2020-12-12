// 128. Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/

// const longestConsecutive = function (nums) {
// 	const map = {};
// 	let max = 0;

// 	for (const item of nums) {
// 		map[item] = 0;
// 	}

// 	for (let item of nums) {
// 		if (map[item] !== 0) {
// 			continue;
// 		}

// 		const _item = item;

// 		let count = 0;
// 		while (map[item] === 0 && map[item] !== undefined) {
// 			map[item] = 1;
// 			count++;
// 			item++;
// 		}

// 		map[_item] = count + (map[item] || 0);

// 		if (max < map[_item]) {
// 			max = map[_item];
// 		}
// 	}

// 	return max;
// };

const longestConsecutive = function (nums) {
	const set = new Set();
	let max = 0;

	for (const item of nums) {
		set.add(item);
	}

	for (const item of nums) {
		if (!set.has(item)) {
			continue;
		}

		let count = 0;
		let _item = item;
		while (set.has(_item)) {
			count++;
			set.delete(_item--);
		}

		_item = item + 1;
		while (set.has(_item)) {
			count++;
			set.delete(_item++);
		}

		if (count > max) {
			max = count;
		}
	}

	return max;
};

function main() {
	debugger;
	// const res = longestConsecutive([100, 4, 200, 1, 3, 2]);
	// const res = longestConsecutive([0, 3, 7, 2, 5, 8, 4, 6, 0, 1]);
	// const res = longestConsecutive([0, 0]);
	const res = longestConsecutive([0, -1]);

	console.log(res);
}

main();
