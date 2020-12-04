// 150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

const operations = {
	"+": (a, b) => a + b,
	"-": (a, b) => a - b,
	"*": (a, b) => a * b,
	"/": (a, b) => a / b,
};

const evalRPN = function (tokens) {
	const numStack = [];

	for (let i = 0; i < tokens.length; i++) {
		const token = tokens[i];
		if (operations[token]) {
			const b = numStack.pop();
			const a = numStack.pop();
			const res = Math.trunc(operations[token](a, b));
			numStack.push(res);
		} else {
			numStack.push(parseInt(token));
		}
	}

	return numStack.pop();
};

function main() {
	debugger;
	// const res = evalRPN(["2", "1", "+", "3", "*"]);
	// const res = evalRPN(["4", "13", "5", "/", "+"]);
	const res = evalRPN([
		"10",
		"6",
		"9",
		"3",
		"+",
		"-11",
		"*",
		"/",
		"*",
		"17",
		"+",
		"5",
		"+",
	]);

	console.log(res);
}

main();
