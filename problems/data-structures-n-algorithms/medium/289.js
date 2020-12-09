// 289. Game of Life
// https://leetcode.com/problems/game-of-life/

const getCells = function (board, i, j) {
	let a = 0,
		b = 0,
		c = 0,
		d = 0,
		e = 0,
		f = 0,
		g = 0,
		h = 0;

	if (i - 1 >= 0) {
		a = board[i - 1][j - 1] || 0;
		b = board[i - 1][j] || 0;
		c = board[i - 1][j + 1] || 0;
	}

	d = board[i][j - 1] || 0;
	e = board[i][j + 1] || 0;

	if (i + 1 < board.length) {
		f = board[i + 1][j - 1] || 0;
		g = board[i + 1][j] || 0;
		h = board[i + 1][j + 1] || 0;
	}

	return [a, b, c, d, e, f, g, h];
};

const getCounts = function (cells) {
	let c0 = 0;
	let c1 = 0;

	for (const cell of cells) {
		if (cell === 0) {
			c0++;
		} else {
			c1++;
		}
	}

	return { 0: c0, 1: c1 };
};

const test1 = function (board, i, j) {
	const cells = getCells(board, i, j);
	const counts = getCounts(cells);

	if (counts[1] < 2) {
		return true;
	}
	return false;
};

const test2 = function (board, i, j) {
	const cells = getCells(board, i, j);
	const counts = getCounts(cells);

	if ((counts[1] === 2 || counts[1] === 3) && board[i][j] === 1) {
		return true;
	}
	return false;
};

const test3 = function (board, i, j) {
	const cells = getCells(board, i, j);
	const counts = getCounts(cells);

	if (counts[1] > 3) {
		return true;
	}
	return false;
};

const test4 = function (board, i, j) {
	const cells = getCells(board, i, j);
	const counts = getCounts(cells);

	if (counts[1] === 3 && board[i][j] === 0) {
		return true;
	}
	return false;
};

const gameOfLife = function (board) {
	const state = new Array(3);

	for (let i = 0; i < 3; i++) {
		if (board[i]) {
			state[i] = [...board[i]];
		} else {
			state[i] = new Array(board[0].length);
			state[i].fill(0);
		}
	}

	let row = 0;

	for (let i = 0; i < board.length; i++) {
		if (i === 0) {
			row = 0;
		} else if (i === board.length - 1) {
			row = i < 2 ? i : 2;
		} else {
			row = 1;
		}
		for (let j = 0; j < board[i].length; j++) {
			if (test1(state, row, j)) {
				board[i][j] = 0;
			} else if (test2(state, row, j)) {
				board[i][j] = 1;
			} else if (test3(state, row, j)) {
				board[i][j] = 0;
			} else if (test4(state, row, j)) {
				board[i][j] = 1;
			}
		}

		if (i + 2 < board.length && i !== 0) {
			state[0] = state[1];
			state[1] = state[2];
			state[2] = [...board[i + 2]];
		}
	}

	return board;
};

function main() {
	// const board = [
	// 	[0, 1, 0],
	// 	[0, 0, 1],
	// 	[1, 1, 1],
	// 	[0, 0, 0],
	// ];

	// const board = [[]];
	// const board = [[0]];
	const board = [
		[1, 1],
		[1, 0],
	];

	debugger;
	const res = gameOfLife(board);
	console.log(res);
}

main();
