import 'tile_position.dart';

class BoardState {
  factory BoardState(List<List<int>> rows) {
    int row = 0;
    int column = 0;

    for (List<int> rowList in rows) {
      for (int tile in rowList) {
        if (tile == emptyTile) {
          return BoardState._(rows, Position(row, column));
        }
        column++;
      }
      column = 0;
      row++;
    }

    throw ArgumentError("The board must contain an empty tile.");
  }

  const BoardState._(this.rows, this.emptyTilePosition);

  final List<List<int>> rows;
  final Position emptyTilePosition;

  static const int emptyTile = 0;
  static const int rowsAmount = 3;
  static const int columnsAmount = 3;

  int getTileAt(Position position) {
    return rows[position.row][position.column];
  }

  @override
  bool operator ==(Object other) {
    if (other is! BoardState) return false;

    for (int rowIndex = 0; rowIndex < rowsAmount; rowIndex++) {
      List<int> row = rows[rowIndex];
      List<int> otherRow = other.rows[rowIndex];

      for (int column = 0; column < row.length; column++) {
        if (row[column] != otherRow[column]) return false;
      }
    }

    return true;
  }

  @override
  int get hashCode => Object.hashAll(rows.expand((row) => row));

  @override
  String toString() {
    return rows.map((row) => row.toString()).join('\n');
  }
}
