module Isogram (isIsogram) where
import Data.List (sort)
import Data.Char (toLower)

isIsogram :: String -> Bool
isIsogram string = and $ zipWith (/=) sorted (tail sorted)
  where sanitize string = map toLower $ filter (`notElem` " -") string
        sorted = sort $ sanitize string
