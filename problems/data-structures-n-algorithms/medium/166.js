// 166. Fraction to Recurring Decimal
// https://leetcode.com/problems/fraction-to-recurring-decimal/

const fractionToDecimal = function (numerator, denominator) {
	if (numerator === 0) {
		return "0";
	}

	let str = "";

	if ((numerator > 0) ^ (denominator > 0)) {
		str += "-";
	}

	const nume = Math.abs(numerator);
	const deno = Math.abs(denominator);

	const dec = Math.floor(nume / deno);
	str = str + dec;

	if (nume % deno === 0) {
		return str;
	}

	str = str + ".";

	const map = {};

	let rem = (nume % deno) * 10;
	while (rem) {
		if (map[rem]) {
			str = str.substring(0, map[rem]) + "(" + str.substring(map[rem]) + ")";
			break;
		}

		map[rem] = str.length;
		const fq = Math.floor(rem / deno);
		str += fq;
		rem = (rem % deno) * 10;
	}

	return str;
};

function main() {
	debugger;
	const res = fractionToDecimal(-50, 8);
	console.log(res);
}

main();
