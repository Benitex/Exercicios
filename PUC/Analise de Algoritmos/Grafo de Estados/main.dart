import "graph.dart";
import "board_state.dart";
import 'tile_position.dart';

void main() {
  print("Generating possible game states...");
  List<BoardState> possibleGameStates = generateAllPossibleBoardStates();
  print("${possibleGameStates.length} possible game states generated.\n");

  print("Generating graph of possible moves...");
  Graph<BoardState> graph = Graph.fromAdjacencyList(
    generatePossibleMoves(possibleGameStates),
  );

  print("Graph generated with ${graph.nodesAmount} nodes and ${graph.edgesAmount} edges.");
  print("The graph has ${graph.componentsAmount} connected components.\n");

  BoardState goal = BoardState([
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, BoardState.emptyTile],
  ]);
  print("Hardest configurations to reach the goal state:");
  print("${graph.getMostDistantNodes(goal)}");
}

List<BoardState> generateAllPossibleBoardStates() {
  List<int> initialBoard = [
    1, 2, 3,
    4, 5, 6,
    7, 8, BoardState.emptyTile,
  ];

  List<BoardState> allPossibleBoards = [
    for (List<int> permutation in _generatePermutations<int>(initialBoard))
      BoardState([
        permutation.sublist(0, 3),
        permutation.sublist(3, 6),
        permutation.sublist(6, 9),
      ]),
  ];

  return allPossibleBoards;
}

/// Generates all permutations of the given list.
/// 
/// Selects one element as the first and removes it from the list, 
/// to generates all permutations of the remaining elements recursively.
List<List<T>> _generatePermutations<T>(List<T> list) {
  if (list.isEmpty) return [[]];

  List<List<T>> permutations = [];

  for (int i = 0; i < list.length; i++) {
    T currentElement = list[i];
    List<T> remainingElements = [
      ...list.sublist(0, i), ...list.sublist(i + 1),
    ];

    for (List<T> subPermutation in _generatePermutations(remainingElements)) {
      permutations.add([currentElement, ...subPermutation]);
    }
  }

  return permutations;
}

Map<BoardState, List<BoardState>> generatePossibleMoves(List<BoardState> boards) {
  Map<BoardState, List<BoardState>> possibleMoves = {};

  // This map is used to reference existing BoardState instances
  // instead of creating new ones
  final Map<BoardState, BoardState> boardMap = {
    for (BoardState b in boards) b: b
  };

  for (BoardState board in boards) {
    possibleMoves[board] = [];

    // There are up to 4 possible moves at each state (each direction)
    // But depending on the empty tile position, moves can become invalid
    List<Position> possiblePositionChanges = [
      // Move tile down (move empty tile up)
      if (board.emptyTilePosition.row > 0)
        Position(board.emptyTilePosition.row - 1, board.emptyTilePosition.column),
      // Move tile up (move empty tile down)
      if (board.emptyTilePosition.row < BoardState.rowsAmount - 1)
        Position(board.emptyTilePosition.row + 1, board.emptyTilePosition.column),
      // Move tile right (move empty tile left)
      if (board.emptyTilePosition.column > 0)
        Position(board.emptyTilePosition.row, board.emptyTilePosition.column - 1),
      // Move tile left (move empty tile right)
      if (board.emptyTilePosition.column < BoardState.columnsAmount - 1)
        Position(board.emptyTilePosition.row, board.emptyTilePosition.column + 1),
    ];

    // Flip the empty tile with the tile in the calculated positions
    for (Position movedTilePosition in possiblePositionChanges) {
      List<List<int>> rows = [for (List<int> row in board.rows) [...row]]; // Deep copy board

      int movedTile = board.getTileAt(movedTilePosition);

      rows[board.emptyTilePosition.row][board.emptyTilePosition.column] = movedTile;
      rows[movedTilePosition.row][movedTilePosition.column] = BoardState.emptyTile;

      possibleMoves[board]!.add(boardMap[BoardState(rows)]!);
    }
  }

  return possibleMoves;
}
