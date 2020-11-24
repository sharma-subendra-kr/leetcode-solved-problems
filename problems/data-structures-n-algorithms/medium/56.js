// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/

const merge = function (intervals) {
	intervals.sort((a, b) => {
		return a[0] - b[0];
	});

	const res = [];
	let ri = -1;

	for (const item of intervals) {
		if (ri === -1) {
			res.push(item);
			ri++;
			continue;
		}

		const back = res[ri];

		if (item[0] <= back[1]) {
			// merge
			if (item[1] > back[1]) {
				back[1] = item[1];
			}
		} else {
			res.push(item);
			ri++;
		}
	}

	return res;
};

function main() {
	// const res = merge([
	// 	[1, 3],
	// 	[2, 6],
	// 	[8, 10],
	// 	[15, 18],
	// ]);

	const res = merge([
		[2, 3],
		[2, 2],
		[3, 3],
		[1, 3],
		[5, 7],
		[2, 2],
		[4, 6],
	]);

	console.log(res);
}

main();
