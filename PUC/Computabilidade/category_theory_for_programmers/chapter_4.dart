import 'dart:math';

double? safeRoot(double number) {
  if (number <= 0) return null;
  return sqrt(number);
}

double? safeReciprocal(double number) {
  if (number == 0) return null;
  return 1 / number;
}

C? Function(A) compose<A, B, C>(C? Function(B?) function1, B? Function(A) function2) {
  return (a) {
    B? result = function2(a);
    if (result == null) return null;
    return function1(result);
  };
}

Function safeRootReciprocal = compose<double, double?, double?>(
  (number) => number == null ? null : safeRoot(number),
  safeReciprocal
);
