// 62. Unique Paths
// https://leetcode.com/problems/unique-paths/

// const uniquePaths = function (m, n) {
// 	const matrix = new Array(m);
// 	for (let i = 0; i < m; i++) {
// 		matrix[i] = new Array(n);
// 	}

// 	for (let i = 0; i < m; i++) {
// 		matrix[i][0] = 1;
// 	}

// 	for (let i = 0; i < n; i++) {
// 		matrix[0][i] = 1;
// 	}

// 	for (let i = 1; i < m; i++) {
// 		for (let j = 1; j < n; j++) {
// 			matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
// 		}
// 	}

// 	return matrix[m - 1][n - 1];
// };

const uniquePaths = function (m, n) {
	const N = m + n - 2; // total no of steps to go down and right to reach destination
	let k = m - 1 || 1; // number of steps to reach bottom
	let l = n - 1 || 1; // number of steps to reach right

	let res = 1;
	for (let i = N; i > 1; i--) {
		res = res * (i / (k * l));
		k = Math.abs(k - 1) || 1;
		l = Math.abs(l - 1) || 1;
	}

	return Math.round(res);
};

function main() {
	debugger;
	const res = uniquePaths(10, 1);
	console.log(res);
}

main();
