// 172. Factorial Trailing Zeroes
// https://leetcode.com/problems/factorial-trailing-zeroes/

const trailingZeroes = function (n) {
	let res = 0;
	let cnt = 1;
	for (let i = 1; i <= n; i += 4) {
		res = res + Math.floor(n / Math.pow(5, cnt));
		cnt++;
	}

	return res;
};

function main() {
	debugger;
	const res = trailingZeroes(75);
	console.log(res);
}

main();
