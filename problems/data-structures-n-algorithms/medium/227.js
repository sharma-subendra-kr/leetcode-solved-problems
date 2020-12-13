// 227. Basic Calculator II
// https://leetcode.com/problems/basic-calculator-ii/

const isDigit = function (c) {
	if (!isNaN(c) && c !== "" && c !== " ") {
		return true;
	}
	return false;
};

const isMulDivOp = function (c) {
	if (c === "/" || c === "*") {
		return true;
	}
	return false;
};

const isAddSubOp = function (c) {
	if (c === "+" || c === "-") {
		return true;
	}
	return false;
};

// const operate = function (n1, op, n2) {
// 	let res;
// 	if (op === "/") {
// 		res = n1 / n2;
// 	} else if (op === "*") {
// 		res = n1 * n2;
// 	} else if (op === "+") {
// 		res = n1 + n2;
// 	} else {
// 		res = n1 - n2;
// 	}

// 	return Math.trunc(res);
// };

// const getNextDigitStart = function (s, iter) {
// 	while (s[iter] === " ") {
// 		iter++;
// 	}
// 	return iter;
// };

// const getNextDigitEnd = function (s, iter) {
// 	while (!isNaN(s[iter]) && s[iter] !== "" && s[iter] !== " ") {
// 		iter++;
// 	}
// 	return iter - 1;
// };

// const calculate = function (s) {
// 	s = s.trim();
// 	const numStack = [];
// 	const operStack = [];
// 	let res = 0;
// 	let iter = 0;

// 	const end = getNextDigitEnd(s, iter);
// 	numStack.push(parseInt(s.substring(iter, end + 1)));
// 	iter = end + 1;

// 	while (numStack.length) {
// 		const c = s.charAt(iter);
// 		if (isDigit(c)) {
// 			const end = getNextDigitEnd(s, iter);
// 			let d = parseInt(s.substring(iter, end + 1));
// 			if (s[iter - 1] === "-") {
// 				d = -d;
// 			}
// 			numStack.push(d);
// 			iter = end;
// 		} else if (isMulDivOp(c)) {
// 			const n1 = numStack.pop();
// 			const op = c;
// 			iter = getNextDigitStart(s, ++iter);
// 			const end = getNextDigitEnd(s, iter);
// 			const n2 = parseInt(s.substring(iter, end + 1));
// 			iter = end;
// 			res = operate(n1, op, n2);
// 			numStack.push(res);
// 		} else if (isAddSubOp(c)) {
// 			operStack.push("+");
// 		} else if (c === "") {
// 			if (numStack.length === 1) {
// 				return numStack[0];
// 			}

// 			const n2 = numStack.pop();
// 			const op = operStack.pop();
// 			const n1 = numStack.pop();
// 			res = operate(n1, op, n2);
// 			numStack.push(res);
// 		}
// 		iter++;
// 	}
// };

// const operate = function (n1, op, n2) {
// 	let res;
// 	if (op === "/") {
// 		res = n1 / n2;
// 	} else if (op === "*") {
// 		res = n1 * n2;
// 	} else {
// 		res = n1 + n2;
// 	}

// 	return Math.trunc(res);
// };

const calculate = function (s) {
	s = s.trim();
	const stack = [];
	let res = 0;
	let iter = 0;
	let currentNumber = 0;
	let operator;

	while (iter <= s.length) {
		const c = s.charAt(iter);
		if (isDigit(c)) {
			currentNumber = currentNumber * 10 + parseInt(c);
		} else if (isMulDivOp(c) || isAddSubOp(c) || iter === s.length) {
			if (operator === "/") {
				const num = stack.pop();
				res = Math.trunc(num / currentNumber);
				stack.push(res);
			} else if (operator === "*") {
				const num = stack.pop();
				res = Math.trunc(num * currentNumber);
				stack.push(res);
			} else if (operator === "-") {
				stack.push(-currentNumber);
			} else {
				stack.push(currentNumber);
			}
			currentNumber = 0;
			operator = c;
		}
		iter++;
	}
	return stack.reduce((acc, val) => {
		return acc + val;
	}, 0);
};

function main() {
	debugger;
	// const res = calculate("3+2*2");
	// const res = calculate(" 3/2 ");
	// const res = calculate(" 3+5 / 2 ");
	// const res = calculate("42");
	const res = calculate("1-1+1");
	console.log(res);
}

main();
