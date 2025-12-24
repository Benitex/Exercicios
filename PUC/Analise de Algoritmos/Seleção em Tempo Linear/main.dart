// Benito André Pepe

import 'dart:math';

void main(List<String> args) {
  if (args.isEmpty) {
    print("Please provide the number of elements as a command line argument.");
    return;
  }

  Random random = Random();

  List<int> list = List.generate(
    int.parse(args[0]),
    (int index) => random.nextInt(100000),
  );
  list.shuffle();

  if (args.length > 2 && args[2] == "print") {
    print(list.toString() + "\n");
  }

  int elementIndex = list.length ~/ 2;
  if (args.length > 1) {
    elementIndex = int.parse(args[1]);
  }

  DateTime start;

  start = DateTime.now();
  print(linearSelection(list, elementIndex));
  print("Linear selection took ${DateTime.now().difference(start).inMicroseconds} microseconds.\n");

  start = DateTime.now();
  print(sortSelection(list, elementIndex));
  print("Sort selection took ${DateTime.now().difference(start).inMicroseconds} microseconds.");
}

Comparable linearSelection(List<Comparable> elements, int elementIndex) {
  if (elementIndex < 0 || elementIndex >= elements.length) {
    throw RangeError("elementIndex must be between 0 and ${elements.length - 1}.");
  }

  if (elements.length == 1) return elements[0];

  Comparable medianOfMedians = getMedianOfMedians(elements);

  // Partition [elements] around [medianOfMedians].
  List<Comparable> elementsLessThanMedian = [];
  List<Comparable> elementsEqualToMedian = [];
  List<Comparable> elementsGreaterThanMedian = [];

  for (Comparable element in elements) {
    if (element < medianOfMedians) {
      elementsLessThanMedian.add(element);
    } else if (element > medianOfMedians) {
      elementsGreaterThanMedian.add(element);
    } else {
      elementsEqualToMedian.add(element);
    }
  }

  // Recursively search in other partitions.
  if (elementIndex < elementsLessThanMedian.length) {
    return linearSelection(elementsLessThanMedian, elementIndex);
  } else if (elementIndex >= elementsLessThanMedian.length + elementsEqualToMedian.length) {
    int newIndex = elementIndex - elementsLessThanMedian.length - elementsEqualToMedian.length;
    return linearSelection(elementsGreaterThanMedian, newIndex);
  }

  return elementsEqualToMedian[0];
}

Comparable getMedianOfMedians(List<Comparable> elements) {
  // Split [elements] into groups of 5.
  List<List<Comparable>> groupsOfFive = [];

  int i;
  for (i = 0; i < elements.length - elements.length % 5; i += 5) {
    groupsOfFive.add(elements.sublist(i, i + 5));
  }
  if (elements.length % 5 != 0) {
    groupsOfFive.add(elements.sublist(i));
  }

  // Sort each group.
  for (List<Comparable> group in groupsOfFive) {
    group.sort();
  }

  // Find the median of each group.
  List<Comparable> medians = [];
  for (List<Comparable> group in groupsOfFive) {
    medians.add(group[group.length ~/ 2]);
  }

  // Find the median of the medians.
  return linearSelection(medians, medians.length ~/ 2);
}

/// Returns the [elementIndex] smallest element in the sorted [elements].<br>
/// The sorting algorithm used is bubble sort.
Comparable sortSelection(List<Comparable> elements, int elementIndex) {
  List sortedList = List.from(elements);

  for (int algorithmIteration = 0; algorithmIteration < sortedList.length; algorithmIteration++) {
    // The algorithm skips the last [algorithmIteration] elements because they are already sorted.
    // (The greatest elements "bubble up" to the end of the list.)
    for (int index = 0; index < sortedList.length - algorithmIteration - 1; index++) {
      if (sortedList[index] > sortedList[index + 1]) {
        Comparable greaterElement = sortedList[index];
        sortedList[index] = sortedList[index + 1];
        sortedList[index + 1] = greaterElement;
      }
    }
  }

  return sortedList[elementIndex];
}

void experiments(List<String> args) {
  if (args.isEmpty) {
    print("Please provide the number of elements as a command line argument.");
    return;
  }

  Random random = Random();

  List<int> linearTimes = [];
  List<int> sortTimes = [];

  for (int i = 0; i < 10; i++) {
    print("Iteration ${i + 1}:");

    List<int> list = List.generate(
      int.parse(args[0]),
      (int index) => random.nextInt(100000),
    );

    if (args.length > 2 && args[2] == "print") {
      print(list.toString() + "\n");
    }

    int elementIndex = list.length ~/ 2;
    if (args.length > 1) {
      elementIndex = int.parse(args[1]);
    }

    DateTime time;
    Comparable linearResult, sortResult;

    time = DateTime.now();    
    linearResult = linearSelection(list, elementIndex);
    linearTimes.add(DateTime.now().difference(time).inMicroseconds);
    print(linearResult);
    print("Linear selection took ${linearTimes[i]} microseconds.\n");

    time = DateTime.now();
    sortResult = sortSelection(list, elementIndex);
    sortTimes.add(DateTime.now().difference(time).inMicroseconds);
    print(sortResult);
    print("Sort selection took ${sortTimes[i]} microseconds.\n");

    if (linearResult != sortResult) {
      throw Exception("The results are different!");
    }
  }

  print("Linear times avarage " + (linearTimes.reduce((a, b) => a + b) / linearTimes.length).toStringAsFixed(2) + " microseconds.");
  print("Sort times avarage " + (sortTimes.reduce((a, b) => a + b) / sortTimes.length).toStringAsFixed(2) + " microseconds.");
}

extension on Comparable {
  bool operator <(Comparable other) => this.compareTo(other) < 0;
  bool operator >(Comparable other) => this.compareTo(other) > 0;
}
