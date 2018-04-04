### Life Events

Given a list of life events, where a life event is just a [birthYear, deathYear] tuple, find the number of people alive in a specific year. E.g., [[0,6], [12,19], [3,8], [2,5], [7,9]].

If unsorted, iterate over the array. If you see a birth year value less than or equal to the target year, increment a counter of people alive up until that year. If you see a death year value less than or equal to the target year, decrement the counter of people alive up until that year. O(n)

If sorted, you can do an early stop once the birth year value exceeds the target year.

Modification 1: How do you find the max value, such that it's not O(n^2)?

\[[Solution](solution.cpp)\]
