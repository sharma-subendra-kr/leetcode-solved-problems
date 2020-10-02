// 50. Pow(x, n)
// Implement pow(x, n), which calculates x raised to the power n (i.e. xn).

#include <stdio.h>
#include <stdlib.h>

double myPow(double x, int n) {
  // x^21
  // x * x ^ 20
  // x * (x ^ 10) ^ 2
  // x * ((x ^ 5) ^ 2) ^ 2
  // x * ((x ^ 2 * x ^ 2 * x) ^ 2) ^ 2

  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return x;
  } else if (n == 2) {
    return x * x;
  } else if (n == -1) {
    return 1 / x;
  } else if (n == -2) {
    return 1 / (x * x);
  }

  if ((int)n % 2 == 1) {
    return x * myPow(x, n - 1);
  } else if ((int)n % 2 == -1) {
    return 1 / x * myPow(x, n + 1);
  } else {
    return myPow(myPow(x, n / 2), 2);
  }
}

int main() {
  int n;
  double x;
  scanf("%lf%d", &x, &n);

  printf("%lf", myPow(x, n));

  return 0;
}