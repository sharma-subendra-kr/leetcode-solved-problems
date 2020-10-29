int comp(const void *a, const void *b) {

	long _a = *((long *)a);
	long _b = *((long *)b);

	if (_a > _b) {
		return 1;
	} else if (_a < _b) {
		return -1;
	} else {
		return 0;
	}
}

// 1. pointer to array
// 2. size of array
// 3. size of each element
// comparator function

// For dynamic array
qsort(arr, 5, sizeof(*arr), comp);
// For static array - not tested
qsort(x, sizeof(arr) / sizeof(*arr), sizeof(*arr), comp);
// * for static array sizeof(arr) gives (number * size of content type)
// * sizeof(*p) means "give me the size of the contents that p points at"
// * but sizeof(int*) means "give me the size of the pointer type itself"
// * On the machine, int is apparently 4 bytes but pointers are 8 bytes (typical
// 64 bit machine).
// * thus sizeof(*arr) gives 4 bytes not 8.
