// 202. Happy Number
// https://leetcode.com/problems/happy-number/

const getDigits = (n) => {
	const digits = [];
	while (n !== 0) {
		digits.push(Math.floor(n % 10));
		n = Math.floor(n / 10);
	}
	return digits;
};

const isHappy = function (n) {
	const map = { n: true };

	while (true) {
		const digits = getDigits(n);

		const sum = digits.reduce((acc, val) => acc + Math.pow(val, 2), 0);
		if (sum === 1) {
			return true;
		} else if (map[sum]) {
			return false;
		}
		map[sum] = true;
		n = sum;
	}
};

function main() {
	debugger;

	const res = isHappy(2);
	console.log(res);
}

main();
