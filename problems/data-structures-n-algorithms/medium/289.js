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
		if (cell === 0 || cell === -1) {
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

	if (counts[1] < 2 && board[i][j] === 1) {
		// board[i][j] = 2;
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

	if (counts[1] > 3 && board[i][j] === 1) {
		// board[i][j] = 2;
		return true;
	}
	return false;
};

const test4 = function (board, i, j) {
	const cells = getCells(board, i, j);
	const counts = getCounts(cells);

	if (counts[1] === 3 && board[i][j] === 0) {
		board[i][j] = -1;
		return true;
	}
	return false;
};

const gameOfLife = function (board) {
	for (let i = 0; i < board.length; i++) {
		for (let j = 0; j < board[i].length; j++) {
			if (test1(board, i, j)) {
				board[i][j] = 2;
				continue;
			} else if (test2(board, i, j)) {
				continue;
			} else if (test3(board, i, j)) {
				board[i][j] = 2;
				continue;
			} else if (test4(board, i, j)) {
				board[i][j] = -1;
				continue;
			}
		}
	}

	for (let i = 0; i < board.length; i++) {
		for (let j = 0; j < board[0].length; j++) {
			if (board[i][j] === -1) {
				board[i][j] = 1;
			} else if (board[i][j] === 2) {
				board[i][j] = 0;
			}
		}
	}

	return board;
};

function main() {
	const board = [
		[0, 1, 0],
		[0, 0, 1],
		[1, 1, 1],
		[0, 0, 0],
	];

	// const board = [[]];
	// const board = [[0]];
	// const board = [
	// 	[1, 1],
	// 	[1, 0],
	// ];

	debugger;
	const res = gameOfLife(board);
	console.log(res);
}

main();
