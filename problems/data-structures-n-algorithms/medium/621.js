// 621. Task Scheduler
// https://leetcode.com/problems/task-scheduler/

const aMap = {
	A: 0,
	B: 1,
	C: 2,
	D: 3,
	E: 4,
	F: 5,
	G: 6,
	H: 7,
	I: 8,
	J: 9,
	K: 10,
	L: 11,
	M: 12,
	N: 13,
	O: 14,
	P: 15,
	Q: 16,
	R: 17,
	S: 18,
	T: 19,
	U: 20,
	V: 21,
	W: 22,
	X: 23,
	Y: 24,
	Z: 25,
};

const leastInterval = function (tasks, n) {
	if (tasks.length === 0) {
		return 0;
	}

	const map = new Array(26);
	map.fill(0);
	const _aMap = { ...aMap };

	for (let i = 0; i < tasks.length; i++) {
		map[_aMap[tasks[i]]]++;
	}

	let max = 0;
	for (const item of map) {
		if (item > max) {
			max = item;
		}
	}

	let sum = 0;
	let maxCount = -1;
	for (const item of map) {
		if (item < max) {
			sum += item;
		} else if (item === max) {
			maxCount++;
		}
	}

	let slots = (max - 1) * n;
	slots -= maxCount * (max - 1);
	let idle = slots - sum;
	idle = idle < 0 ? 0 : idle;

	return tasks.length + idle;
};

function main() {
	debugger;
	// const res = leastInterval(["A", "A", "A", "B", "B", "B"], 2);
	// const res = leastInterval(["A", "A", "A", "B", "B", "B"], 0);
	// const res = leastInterval(
	// 	["A", "A", "A", "A", "A", "A", "B", "C", "D", "E", "F", "G"],
	// 	2
	// );
	const res = leastInterval([], 0);
	console.log(res);
}

main();
