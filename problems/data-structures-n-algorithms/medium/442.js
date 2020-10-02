// 442. Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/
//
//
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    nums.sort(function (a, b) {
        if (a < b) {
            return -1;
        } else if (a > b) {
            return 1;
        } else {
            return 0;
        }
    });
    
    var len = nums.length;
    var arr = new Array(len);
    var count = 0;
    for (var i = 0; i <  len; i++) {
        if (nums[i] === nums[i+1]) {
            arr[count++] = nums[i];
            i++;
        }    
    }
    
    var arrR = new Array(count);
    for (var i = 0; i <  count; i++) {
        arrR[i] = arr[i];
    }
    
    return arrR;
};
