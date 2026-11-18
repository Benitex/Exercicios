module Anagram (anagramsFor) where

import Data.List
import Data.Char (toLower)

anagramsFor :: String -> [String] -> [String]
anagramsFor word candidates = filter isAnagram candidates
  where sanitize = map toLower
        sorted = sort . sanitize
        sortedWord = sorted word
        isAnagram candidate = sorted candidate == sortedWord && sanitize word /= sanitize candidate

-- anagramsFor :: String -> [String] -> [String]
-- anagramsFor word candidates = filter (\candidate -> sanitize candidate `elem` availableWords) candidates
--   where sanitize = map toLower
--         availableWords = delete (sanitize word) $ nub $ permutations $ sanitize word
