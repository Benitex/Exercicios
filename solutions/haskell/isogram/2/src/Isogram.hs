module Isogram (isIsogram) where
import Data.List (sort)
import Data.Char (toLower)

isIsogram :: String -> Bool
isIsogram string = and $ zipWith (/=) sorted (tail sorted)
  where sanitize = map toLower . filter (`notElem` " -")
        sorted = sort $ sanitize string
