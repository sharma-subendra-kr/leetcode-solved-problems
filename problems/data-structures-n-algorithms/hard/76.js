// 76. Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/

const copyMap = (o, d) => {
	for (const key in o) {
		d[key] = o[key];
	}
};

// time limit exceeded for last test case
const minWindow = function (s, t) {
	const map = {};
	const cpMap = {};
	for (const item of t) {
		if (!map[item]) {
			map[item] = 1;
		} else {
			map[item]++;
		}
	}
	copyMap(map, cpMap);

	let minFirst = -1;
	let minLast = -1;
	let first = -1;
	let second = -1;
	let last = -1;
	let len = 0;

	for (let i = 0; i < s.length; i++) {
		const c = s[i];
		if (cpMap[c] && first === -1) {
			first = i;
			cpMap[c]--;
			len++;
		} else if (cpMap[c]) {
			if (len === 1 && second === -1) {
				second = i;
			}
			cpMap[c]--;
			len++;
		}

		if (first !== -1 && second === -1 && s[i] === s[first] && i > first) {
			second = i;
		}

		if (len === t.length) {
			last = i;
			if (second !== -1) {
				i = second - 1;
			}
			second = -1;
			copyMap(map, cpMap);
			len = 0;

			if (minLast - minFirst > last - first || minLast === -1) {
				minLast = last;
				minFirst = first;
			}
			last = -1;
			first = -1;
		}
	}

	return s.substring(minFirst, minLast + 1);
};

function main() {
	debugger;
	const res = minWindow("ADOBECODEBANC", "ABC");
	// const res = minWindow("a", "a");
	// const res = minWindow("bba", "ab");
	console.log(res);
}

main();
