### Stocks Ultra Sorter

Given several sorted lists of stock prices, return a combined sorted list of all of the stock prices.

Input:
{
  "MSFT": [54, 56, 89, 100],
  "GOOG": [33, 54, 55, 90],
  "AAPL": [33, 36, 60, 90, 100],
  "META": [56, 75, 89, 112],
}

Result:
[
  (33,"GOOG"),
  (33,"AAPL"),
  (36,"AAPL"),
  (54,"MSFT"),
  (54,"GOOG"),
  (55,"GOOG"),
  (56,"META"),
  (56,"MSFT"),
  (60,"AAPL"),
  (75,"META"),
  (89,"MSFT"),
  (89,"META"),
  (90,"AAPL"),
  (90,"GOOG"),
  (100,"AAPL"),
  (100,"MSFT"),
  (112,"META"),
]


Modification 1: Solution cannot use any external sorting tools or be O(n log n).

\[[Solution](solution.cpp)\]
