/**
 * Initialize your data structure here.
 */
const RandomizedSet = function () {
	this.locations = {};
	this.array = [];
};

/**
 * Inserts a value to the set. Returns true if the set did not already contain the specified element.
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.insert = function (val) {
	if (this.locations[val] === undefined) {
		this.array.push(val);
		this.locations[val] = this.array.length - 1;
		return true;
	}
	return false;
};

/**
 * Removes a value from the set. Returns true if the set contained the specified element.
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.remove = function (val) {
	if (this.locations[val] !== undefined) {
		const index = this.locations[val];

		const temp = this.array[index];
		this.array[index] = this.array[this.array.length - 1];
		this.array[this.array.length - 1] = temp;
		this.array.length = this.array.length - 1;

		delete this.locations[val];
		this.locations[this.array[index]] = index;

		return true;
	}
	return false;
};

/**
 * Get a random element from the set.
 * @return {number}
 */
RandomizedSet.prototype.getRandom = function () {
	const rand = Math.trunc(Math.random() * this.array.length);
	return this.array[rand];
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = new RandomizedSet()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */

const obj = new RandomizedSet();
const res = [
	obj.insert(0),
	obj.insert(1),
	obj.remove(0),
	obj.insert(2),
	obj.remove(1),
	obj.getRandom(),
];

console.log(res);
