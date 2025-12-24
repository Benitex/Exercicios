class Graph<T> {
  Map<T, List<T>> _adjacencyList = {};

  Graph.fromAdjacencyList(Map<T, List<T>> adjacencyList) {
    _adjacencyList = adjacencyList;
  }

  int get nodesAmount => _adjacencyList.length;

  int get edgesAmount {
    int amount = 0;
    for (T node in _adjacencyList.keys) {
      amount += _adjacencyList[node]!.length;
    }
    return amount ~/ 2;
  }

  int get componentsAmount {
    int amount = 0;

    Set<T> unvisitedNodes = {..._adjacencyList.keys};
    while (unvisitedNodes.isNotEmpty) {
      // Each BFS traversal visits all nodes in a connected component
      // So, each iteration corresponds to one connected component
      amount++;

      Set<T> visitedNodes = breadthFirstSearch(unvisitedNodes.first).visitedNodes;
      unvisitedNodes.removeAll(visitedNodes);
    }

    return amount;
  }

  ({Set<T> visitedNodes, List<Set<T>> levels}) breadthFirstSearch(T startNode) {
    List<Set<T>> levels = [{startNode}];
    Set<T> visitedNodes = {startNode};

    int currentLevel = 0;
    while (levels[currentLevel].isNotEmpty) {
      levels.add({});

      // Fill the new level with the neighbors of the current level
      for (T node in levels[currentLevel]) {
        for (T neighbor in _adjacencyList[node]!) {
          if (visitedNodes.add(neighbor)) {
            levels[currentLevel + 1].add(neighbor);
          }
        }
      }

      currentLevel++;
    }
    levels.removeLast(); // Remove the last (empty) level

    return (visitedNodes: visitedNodes, levels: levels);
  }

  Set<T> getMostDistantNodes(T startNode) {
    return breadthFirstSearch(startNode).levels.last;
  }
}
