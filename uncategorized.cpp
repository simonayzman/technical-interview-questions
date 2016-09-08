/*
  Given several sorted lists of stock prices, return a combined sorted list of
  all of them.
*/
--------------------------------------------------------------------------------
/*
  Given an array of n+1 integers (each of which is selected from the set of
  numbers from 1 to n). Write an algorithm that finds any duplicate.
*/
--------------------------------------------------------------------------------
/*
  Imagine a race with R racers and S sensors are regular intervals along the
  race track. Design a system that can process a "tick" (a combination of
  racer Rx crossing sensor Sy) at a time and that can determine who is winning
  at the moment in constant time
*/
--------------------------------------------------------------------------------
/*
  Given two linked lists, find the first node of intersection.
*/
--------------------------------------------------------------------------------
/*
  Given an interconnected cluster of computers, design a system where a single
  script can be deployed to a single origin machine that must then communicate
  (to itself and) to all of the other machines that that script needs to be
  executed.

  (Modification) Multiple different scripts can be deployed to different origin
  machines and need to communicate execution.

  (Modification) A single script might need to be run multiple times, but the
  instruction is given at different times and the same script might be deployed
  to different origin machines during each request.
*/
--------------------------------------------------------------------------------
/*
  Given a keyword and an array of pairs (a keyword and the page it appears in
  a book, where a keyword might appear multiple times throughout the book), find
  the first page the given keyword appears on

  (Modification) You may not use a hash table.

  (Modification) Each pair is received in a live stream (a.k.a., array changes).
*/

// Preprocess array of pairs into hash table. O(n) time.
// Algorithm to find first instance of given keyword. O(1) time.

// Preprocess array by sorting it based on keyword, then page. O(n log n) time.
// Algorithm to find first instance of given keyword. O(log n) time.

// Insert each pair into a binary search tree of pairs. O(log n) time.
// Algorithm to find first instance of given keyword. O(log n) time.

--------------------------------------------------------------------------------
/*
  Given a black and white image, represented as a multidimensional array of
  pixels where the color black is 0 and the color white is 1, and particular
  pixel coordinate, find the perimeter of the contiguous area occupied by the
  color at that pixel coordinate.

  e.g.        col ---->

          |---|-------|---|---|
    row   | 0 | 1   1 | 0 | 1 |     Assuming (row, col) format and 0-based
     |    |---|---|   |   |---|     indexes, pixel (3, 1) contains the color 1.
     |    | 0   0 | 1 | 0   0 |
    \|/   |   |___|   |       |     You must find the perimeter of all of the
          | 0 | 1   1 | 0   0 |     1's that occupy the contiguous shape started
          |   |   |---|---|   |     by the first indicated 1.
          | 0 | 1 | 0 | 1 | 0 |
          |---|---|---|---|---|
*/

unsigned int perimeter(const vector<vector<int>>& image,
                        unsigned int row,
                        unsigned int col)
{
  if (image.size() <= row || image[0].size() <= col || row == 0 || col == 0)
  {
    return 0;
  }
  vector<vector<bool>> visited;
  fillWithFalse(visited);

  unsigned int perimeter = 0, value = image[row][col];

  perimeterHelper(image, visited, row, col, perimeter, value);

  return perimeter;
}

bool perimeterHelper(const vector<vector<int>>& image,
                      const vector<vector<int>>& visited,
                      unsigned int currentRow,
                      unsigned int currentCol,
                      unsigned int& perimeter,
                      unsigned int value)
{

}
--------------------------------------------------------------------------------
/*
  Given an array of unique words, write a member function of the BST class that
  creates a binary search tree with minimal height.
*/

// Can sort first in O(n log n) time, and then recursively add in O(n)
// If given to us sorted, we can accomplish in O(n).
--------------------------------------------------------------------------------
/*
  Imagine a party that has a table of appetizers containing individual plates of
  vegetable, shrimp, and beef appetizers. The server behind the table has an
  interest in giving the oldest dish available at that table, so as to prevent
  food poisoning by keeping a dish around longer than it needs to be. The
  server can replenish the stock of each appetizer, one dish at a time. A guest
  can come up to the table and request one specific appetizer. However, a
  guest might also not care what he/she receives, and can therefore request that
  the server choose the dish themselves. Design and implement a system that
  satisfies all of these needs
*/

// Appetizer class. Contains a timestamp and an appetizer type.
// AppetizerTable class. Contains three "appetizer" queues, each constrained
// to one specific appetizer type.
// - replenish{Beef,Shrimp,Vegetable}: Adds the specific appetizer with a new
//   timestamp to its appetizer queue
// - serve{Beef,Shrimp,Vegetable}: Removes the front (oldest) appetizer in that
//   specific appetizer queue
// - serveAnyAppetizer: Checks the front (oldest) appetizer on each appetizer
//   queue and serves the one with the oldest timestamp.

// A way to extend this would be to have a hash table that maps a specific
// appetizer type to its queue. This allows for more appetizer types.

--------------------------------------------------------------------------------
/*
  Implement a data structure that accomplishes key/value pair insertion in O(1)
  time, key/value pair removal in O(1) time, key existence confirmation in O(1)
  time, random key/value pair retrieval in O(1) time.
*/

// InstaRandom class contains a hash table of key/value pairs, an array of keys,
// and another hash table that maps the keys to their index positions in the
// array. Remove is the most complicated function to implement because it
// requires the subsequent holes in the key array to be filled (by swapping the
// removed key with the last key and updating the second hash table).
