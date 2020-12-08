// 454. 4Sum II
// https://leetcode.com/problems/4sum-ii/

// this probably works for unique solutions this is not solution to the current problem
// const fourSumCount = function (A, B, C, D) {
// 	A.sort((a, b) => a - b);
// 	B.sort((a, b) => a - b);
// 	C.sort((a, b) => a - b);
// 	D.sort((a, b) => a - b);

// 	const len = A.length;

// 	let res = 0;

// 	let bi = 0;
// 	let ci = 0;
// 	let di = 0;

// 	for (let i = 0; i < len; i++) {
// 		const a = A[i];

// 		while (bi < len || ci < len || di < len) {
// 			const b = B[bi === len ? bi - 1 : bi];
// 			const c = C[ci === len ? ci - 1 : ci];
// 			const d = D[di === len ? di - 1 : di];

// 			const sum = a + b + c + d;

// 			if (sum === 0) {
// 				ci = ci !== len ? ci + 1 : ci;
// 				bi = bi !== len ? bi + 1 : bi;
// 				di = di !== len ? di + 1 : di;

// 				res++;
// 				continue;
// 			}

// 			const diff1 = sum - b;
// 			const diff2 = sum - c;
// 			const diff3 = sum - d;

// 			const maxDiff = Math.max(diff1, diff2, diff3);

// 			if (diff1 === maxDiff) {
// 				bi++;
// 			} else if (diff2 === maxDiff) {
// 				ci++;
// 			} else {
// 				di++;
// 			}
// 		}
// 		bi = 0;
// 		ci = 0;
// 		di = 0;
// 	}

// 	return res;
// };

const fourSumCount = function (A, B, C, D) {
	const len = A.length;

	let res = 0;

	const map = {};

	for (let i = 0; i < len; i++) {
		for (let j = 0; j < len; j++) {
			if (!map[A[i] + B[j]]) {
				map[A[i] + B[j]] = 1;
			} else {
				map[A[i] + B[j]]++;
			}
		}
	}

	for (let i = 0; i < len; i++) {
		for (let j = 0; j < len; j++) {
			if (map[0 - (C[i] + D[j])]) {
				res += map[0 - (C[i] + D[j])];
			}
		}
	}

	return res;
};

function main() {
	const A = [1, 2];
	const B = [-2, -1];
	const C = [-1, 2];
	const D = [0, 2];

	// const A = [-1, -1];
	// const B = [-1, 1];
	// const C = [-1, 1];
	// const D = [1, -1];

	debugger;
	const res = fourSumCount(A, B, C, D);
	console.log(res);
}

main();
