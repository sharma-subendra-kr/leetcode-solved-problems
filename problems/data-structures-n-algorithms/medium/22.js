// 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/

var copy = function (str, arr) {
	return arr.map(o => {
		return str + o;
	});
}

var generate = function (left, right){
	var arr;
	if (left === right) {
		var str = "(";
		arr = generate(left - 1, right);
		arr = copy(str, arr);
	}else if (left < right && left != 0) {
		var str1 = "(";
		var arr1 = generate(left - 1, right);
		arr1 = copy(str1, arr1);

		var str2 = ")";
		var arr2 = generate(left, right - 1);
		arr2 = copy(str2, arr2);
		
		arr = [...arr1, ...arr2];
	}else if (right > left) {
		if (right - 1 == 0) {
			return [")"];
		}
		var str = ")";
		arr = generate(left, right - 1);
		arr = copy(str, arr);
	}

	return arr;
};

var generateParenthesis = function(n) {
	if (n == 0) {
		return [];
	}  

	return generate(n, n);
};

var main = function () {
	var n = 3;
	var arr = generateParenthesis(n);

	for (let item of arr) {
		console.log(item);
	}
}

main();