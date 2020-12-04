// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/

const dfs = function (i, j, grid) {
	if (
		i === -1 ||
		j === -1 ||
		i === grid.length ||
		j === grid[0].length ||
		grid[i][j] === "-1" ||
		grid[i][j] === "0"
	) {
		return false;
	}

	grid[i][j] = "-1";

	dfs(i - 1, j, grid);
	dfs(i + 1, j, grid);
	dfs(i, j + 1, grid);
	dfs(i, j - 1, grid);

	return true;
};

const numIslands = function (grid) {
	let res = 0;
	for (let i = 0; i < grid.length; i++) {
		for (let j = 0; j < grid[i].length; j++) {
			if (grid[i][j] !== "-1") {
				const flag = dfs(i, j, grid);
				if (flag === true) {
					res++;
				}
			}
		}
	}
	return res;
};

function main() {
	// const grid = [
	// 	["1", "1", "1", "1", "0"],
	// 	["1", "1", "0", "1", "0"],
	// 	["1", "1", "0", "0", "0"],
	// 	["0", "0", "0", "0", "0"],
	// ];

	// const grid = [
	// 	["1", "1", "0", "0", "0"],
	// 	["1", "1", "0", "0", "0"],
	// 	["0", "0", "1", "0", "0"],
	// 	["0", "0", "0", "1", "1"],
	// ];

	const grid = [
		["1", "1", "1"],
		["0", "1", "0"],
		["0", "1", "0"],
	];

	debugger;
	const res = numIslands(grid);
	console.log(res);
}

main();
