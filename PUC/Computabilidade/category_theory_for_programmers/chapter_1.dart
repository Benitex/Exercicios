void main() {
  final firstComposition = compose<int, int, double>(
    (x) => x / 2,
    (x) => x + 1
  );

  final composedFunction = compose<int, double, String>(
    (x) => x.toString(), firstComposition
  );

  Function identityBefore = compose<int, int, String>(
    composedFunction, identity
  );

  Function identityAfter = compose<int, String, String>(
    identity, composedFunction
  );

  print("${composedFunction(10)} == ${identityBefore(10)} --> ${composedFunction(10) == identityBefore(10)}");
  print("${composedFunction(10)} == ${identityAfter(10)} --> ${composedFunction(10) == identityAfter(10)}");
}

// Function compose(Function function1, Function function2) {
C Function(A) compose<A, B, C>(C Function(B) function1, B Function(A) function2) {
  return (a) => function1(function2(a));
}

// identity(x) => x;
T identity<T>(T x) => x;
