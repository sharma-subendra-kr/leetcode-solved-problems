// 322. Coin Change
// https://leetcode.com/problems/coin-change/

const getCache = function (cache, amount) {
	if (cache[amount]) {
		return cache[amount];
	}
	return false;
};

const setCache = function (cache, amount, res) {
	if (!cache[amount]) {
		cache[amount] = res;
	}
};

// cannot pass count and keep adding cuz one previous cached path might have more number of coins
const dfs = function (coins, amount, cache) {
	if (amount === 0) {
		return 0;
	}

	const cRes = getCache(cache, amount);
	if (cRes) {
		return cRes;
	}

	let res = Number.MAX_SAFE_INTEGER;
	let min = Number.MAX_SAFE_INTEGER;
	for (let i = 0; i < coins.length; i++) {
		if (amount >= coins[i]) {
			res = Math.min(res, dfs(coins, amount - coins[i], cache));
			if (res < min) {
				res++;
				min = res;
			}
		}
	}

	setCache(cache, amount, min);

	return min;
};

const coinChange = function (coins, amount) {
	const cache = {};
	const res = dfs(coins, amount, cache);
	return res === Number.MAX_SAFE_INTEGER ? -1 : res;
};

function main() {
	debugger;
	// const res = coinChange([1, 2, 3], 11);
	// const res = coinChange([3, 2, 1], 11);
	// const res = coinChange([5, 4, 3], 11);
	// const res = coinChange([1], 0);
	// const res = coinChange([186, 419, 83, 408], 6249);
	// const res = coinChange([2], 3);
	const res = coinChange([3, 7, 405, 436], 8839);

	console.log(res);
}

main();
