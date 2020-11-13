// 155. Min Stack
// https://leetcode.com/problems/min-stack/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *stack;
	int top;
	int length;

	int *minArr;
	int minTop;
} MinStack;

/** initialize your data structure here. */

MinStack *minStackCreate() {
	MinStack *minStack = (MinStack *)malloc(sizeof(MinStack));
	minStack->stack = (int *)malloc(sizeof(int) * 100);
	minStack->length = 100;
	minStack->top = -1;

	minStack->minArr = (int *)malloc(sizeof(int) * 100);
	minStack->minTop = -1;
	return minStack;
}

void minStackPush(MinStack *obj, int x) {
	int *nStack, i;
	if (obj->top == obj->length - 1) {
		nStack = (int *)malloc(sizeof(int) * obj->length * 2);

		for (i = 0; i < obj->length; i++) {
			nStack[i] = obj->stack[i];
		}
		obj->stack = nStack;
		obj->length *= 2;
	}

	if (obj->minTop == -1 || x <= obj->minArr[obj->minTop]) {
		obj->minArr[++obj->minTop] = x;
	}

	obj->stack[++obj->top] = x;
}

void minStackPop(MinStack *obj) {
	if (obj->stack[obj->top] == obj->minArr[obj->minTop]) {
		obj->minTop--;
	}
	obj->top--;
}

int minStackTop(MinStack *obj) { return obj->stack[obj->top]; }

int minStackGetMin(MinStack *obj) { return obj->minArr[obj->minTop]; }

void minStackFree(MinStack *obj) { free(obj); }

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/