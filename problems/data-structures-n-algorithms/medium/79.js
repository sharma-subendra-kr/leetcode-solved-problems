// 79. Word Search
// https://leetcode.com/problems/word-search/

const dfs = function (i, j, board, word, wordIndex, visited) {
	if (
		i === -1 ||
		j === -1 ||
		i === board.length ||
		j === board[0].length ||
		board[i][j] !== word[wordIndex] ||
		wordIndex === word.length ||
		visited[i + "-" + j]
	) {
		return false;
	} else if (wordIndex === word.length - 1 && !visited[i + "-" + j]) {
		return true;
	}

	visited[i + "-" + j] = true;

	if (
		dfs(i - 1, j, board, word, wordIndex + 1, visited) ||
		dfs(i + 1, j, board, word, wordIndex + 1, visited) ||
		dfs(i, j + 1, board, word, wordIndex + 1, visited) ||
		dfs(i, j - 1, board, word, wordIndex + 1, visited)
	) {
		return true;
	}

	visited[i + "-" + j] = false;
};

const exist = function (board, word) {
	for (let i = 0; i < board.length; i++) {
		for (let j = 0; j < board[i].length; j++) {
			if (word[0] === board[i][j]) {
				const flag = dfs(i, j, board, word, 0, {});
				if (flag === true) {
					return true;
				}
			}
		}
	}
	return false;
};

function main() {
	const board = [
		["a", "a", "a", "a"],
		["a", "a", "a", "a"],
		["a", "a", "a", "a"],
	];
	const word = "aaaaaaaaaaaaa";

	const flag = exist(board, word);
	console.log(flag);
}

main();
