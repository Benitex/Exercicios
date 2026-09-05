module Queens (boardString, canAttack) where

boardString :: Maybe (Int, Int) -> Maybe (Int, Int) -> String
boardString white black = unlines [unwords $ row rowNumber white black | rowNumber <- [0..7]]
  where row number white black = [cell (number, column) white black | column <- [0..7]]
        cell position white black
          | Just (position) == white = "W"
          | Just (position) == black = "B"
          | otherwise = "_"

canAttack :: (Int, Int) -> (Int, Int) -> Bool
canAttack (whiteRow, whiteColumn) (blackRow, blackColumn)
  | whiteRow == blackRow = True
  | whiteColumn == blackColumn = True
  | otherwise = abs (whiteRow - blackRow) == abs (whiteColumn - blackColumn)
