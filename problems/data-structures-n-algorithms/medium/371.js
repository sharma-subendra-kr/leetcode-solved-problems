// 371. Sum of Two Integers
// https://leetcode.com/problems/sum-of-two-integers/

// const getSum = function (a, b) {
// 	let carry = 0;
// 	let count = 0;
// 	let res = 0;
// 	while (count < 32) {
// 		let mask = 1;
// 		mask <<= count;

// 		const _a = a & mask;
// 		const _b = b & mask;

// 		res = res | (_a ^ _b ^ carry);

// 		if ((_a & _b) !== 0 || (_a & carry) !== 0 || (_b & carry) !== 0) {
// 			carry = 1 << (count + 1);
// 		}

// 		count++;
// 	}

// 	return res;
// };

const getSum = function (a, b) {
	let c;
	while (b !== 0) {
		c = a & b;
		a = a ^ b;
		b = c << 1;
	}

	return a;
};

function main() {
	debugger;
	const res = getSum(-1, 2);
	console.log(res);
}

main();
