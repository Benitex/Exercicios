Function memoize(Function function) {
  Map cache = {};
  return (paramether) {
    if (cache.containsKey(paramether)) return cache[paramether];

    var result = function();
    cache[paramether] = result;

    return result;
  };
}
