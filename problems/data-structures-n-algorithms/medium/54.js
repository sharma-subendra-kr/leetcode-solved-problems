// 54. Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/

const spiralOrder = function (matrix) {
	const res = new Array(matrix.length * matrix[0].length);

	const m = matrix[0].length;
	const n = matrix.length;

	let mod0S = 0;
	let mod0E = m - 1;
	let mod0R = 0;

	let mod1S = 1;
	let mod1E = n - 1;
	let mod1C = m - 1;

	let mod2S = m - 2;
	let mod2E = 0;
	let mod2R = n - 1;

	let mod3S = n - 2;
	let mod3E = 1;
	let mod3C = 0;

	let count = 0;
	let iter = 0;

	while (count !== res.length) {
		if (iter % 4 === 0) {
			for (let i = mod0S; i <= mod0E; i++) {
				res[count++] = matrix[mod0R][i];
			}

			mod0S++;
			mod0E--;
			mod0R++;
		} else if (iter % 4 === 1) {
			for (let i = mod1S; i <= mod1E; i++) {
				res[count++] = matrix[i][mod1C];
			}

			mod1S++;
			mod1E--;
			mod1C--;
		} else if (iter % 4 === 2) {
			for (let i = mod2S; i >= mod2E; i--) {
				res[count++] = matrix[mod2R][i];
			}

			mod2S--;
			mod2E++;
			mod2R--;
		} else {
			for (let i = mod3S; i >= mod3E; i--) {
				res[count++] = matrix[i][mod3C];
			}

			mod3S--;
			mod3E++;
			mod3C++;
		}

		iter++;
	}

	return res;
};

function main() {
	// const matrix = [
	// 	[1, 2, 3],
	// 	[4, 5, 6],
	// 	[7, 8, 9],
	// ];

	// const matrix = [
	// 	[1, 2, 3, 4],
	// 	[5, 6, 7, 8],
	// 	[9, 10, 11, 12],
	// ];

	const matrix = [[3], [2]];

	debugger;
	const res = spiralOrder(matrix);
	console.log(res);
}

main();
