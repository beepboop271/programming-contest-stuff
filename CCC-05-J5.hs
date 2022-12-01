
respond :: Bool -> String
respond True = "YES"
respond False = "NO"

isA :: String -> Bool
isA "A" = True
isA ('B':mwS@(_:_)) = (s == 'S') && (isMonkey mw)
  where mw = init mwS
        s = last mwS
isA _ = False

isMonkey :: String -> Bool
isMonkey w
  | isA w = True
  | otherwise = any valid (comb w "")
  where
    comb :: String -> String -> [(String, String)]
    comb (x:xs) acc = (reverse (x:acc), xs):(comb xs (x:acc))
    comb [] _ = []
    valid :: (String, String) -> Bool
    valid (aw, n:mw) = (isA aw) && (n == 'N') && (isMonkey mw)
    valid _ = False

loop = do
  line <- getLine
  case line of
    "X" -> return ()
    otherwise -> do
      putStrLn (respond (isMonkey line))
      loop

main = loop
