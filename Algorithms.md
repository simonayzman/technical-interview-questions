## Algorithms

#### Fizz Buzz

Write a function that cycles through the integers between 1 and n, inclusive.
If the integer is divisible by 3, output "Fizz" on its own line.
If the integer is divisible by 5, output "Buzz" on its own line.
If the integer is divisible by both, output "FizzBuzz" on its own line.
If the integer is divisible by neither, output the integer itself on its own line.

For example, cycling between 1 and 16 produces the following output (condensed to fit on one line):

    1, 2, Fizz, 4, Buzz, Fizz, 7, 8, Fizz, Buzz, 11, Fizz, 13, 14, FizzBuzz, 16

Use the following function declaration:

    void fizzBuzz(int n);

\[[Solution](solutions/fizz-buzz.cpp)\]

#### Integer Set Duplicates
Given an array of n+1 integers (each of which is selected from the set of numbers from 1 to n),
write an algorithm that finds any duplicate. For example, you might be given arrays like so:
[2, 3, 3, 1, 1], [4, 1, 3, 2, 4], and [2, 2, 2, 2, 2]. All of them select from the set {1, 2, 3, 4}.

unsigned int anyDuplicate(vector<unsigned int> numbers) {
  unordered_set<unsigned int> numberExistence;
  for (int i = 0; i < numbers.size(); ++i) {
    unsigned int currentNumber = numbers[i];
    if (numberExistence.contains(currentNumber)) {
      return currentNumber;
    } else {
      numberExistence.insert(currentNumber);
    }
  }
  throw -1; // Duplicates MUST exist
}

\[[Solution](solutions/integer-set-duplicates.cpp)\]

#### Palindrome Numbers

Print out all the 8 digit palindromes.

Note. Prefixed 0's do not count for valid palindromes.

// Assume number of digits is even
void printValidPalindromes(unsigned int numberOfDigits) {

  bool isEven = numberOfDigits % 2 == 0;

  unsigned int halfNumberOfPlaces = numberOfDigits / 2;
  unsigned long long minLeftNumber = pow(10, halfNumberOfPlaces - 1);
  unsigned long long maxLeftNumber = minLeftNumber * 10 - 1;

  unsigned long long currentLeftTemp;
  unsigned long long currentRight = 0;
  for(int currentLeft = minLeftNumber; currentLeft <= maxLeftNumber; currentLeft++) {
    currentLeftTemp = currentLeft;
    while (currentLeftTemp > 0) {
      currentRight = currentRight * 10 + currentLeftTemp % 10;
      currentLeftTemp /= 10;
    }
    if (isEven) {
      cout << currentLeft * pow(10, halfNumberPlaces) + currentRight << endl;
    } else {
      for (int i = 0; i < 10; ++i) {
        cout << (currentLeft * 10 + i) * pow(10, halfNumberPlaces) + currentRight << endl;
      }
    }
  }
}

#### Median Finder

Given two sorted arrays, find the median of what would be the super sorted array.

// O(n) solution exists. O(log n) solution is possible and exists.

### Prefix Expression Evaluation

Given a string containing a prefix expression, compute the value of the expression. For example:

Prefix expression:
/ - 15 * / 3 2 5 5
Value = 1.5

Relevant infix expression:
(15 - (3 / 2) * 5) / 5

You could also make this an infix or postfix evaluation problem, but you can just change the order
of where an expression is evaluated via the stack.

// Solution: Use a stack to get one element at a time (numbers could be multiple characters so
// assume that it's whitespace separated. When you come upon an operation, push it onto the stack.
// When you come upon a first number, push it onto the stack. When you come upon a second number,
// pop the top number off and pop the operation off, and perform the operation on the second number
// and the popped off (first) number.

double Evaluate(vector<string> &input)
{
    vector<double> result;

    for(int i = input.size() - 1;i >= 0; i--)
    {
        if(!IsOperator(input[i]))
        {
            result.push_back(stoi(input[i]));
        }
        else
        {
            Assert(result.size() >= 2);

            double op1 = result.back();
            result.pop_back();

            double op2 = result.back();
            result.pop_back();

            double answer = PerformOperation(op1, op2, input[i]);
            result.push_back(answer);
        }
    }

    Assert(result.size() == 1);
    return result.back();
}

double PerformOperation(double op1, double op2, string oper)
{
    switch(op)
    {
        op1 oper op2

        case "/"
          op == 0
            throw divideByzero
    }
}

bool IsOperator(string op)
{
    return (op == "+" || op == "-" || op == "*" || op == "/");
}

#### Life Events

Given a list of life events, where a life event is just a [birthYear, deathYear] tuple, find the
number of people alive in a specific year. E.g., [[0,6], [12,19], [3,8], [2,5], [7,9]].

If unsorted, iterate over the array. If you see a birth year value less than or equal to the target
year, increment a counter of people alive up until that year. If you see a death year value less
than or equal to the target year, decrement the counter of people alive up until that year. O(n)

If sorted, you can do an early stop once the birth year value exceeds the target year.

(Modification) How do you find the max value, such that it's hopefully not O(n^2)?

#### Process Invoker

Assume that a Process consistents of a process id (pid) and a list of pids representing invoked
processes (child processes) by that Process. Given a list of Process objects and a specific pid,
implement a function that returns all of the child processes by invoked that specific pid (recursively).

// Tree, with traversal? Hashset?

#### Minimum Maze Path

Given an m x n matrix of integers, starting from the upper left hand corner and moving only down or
right, find the minimum possible value of a path to get to the bottom right hand corner. For example,

|---|---|---|---|---|
| 1 | 0 | 8 | 5 | 1 |
|---|---|---|---|---|
| 7 | 5 | 8 | 9 | 2 |
|---|---|---|---|---|
| 3 | 6 | 5 | 9 | 3 |
|---|---|---|---|---|
| 0 | 1 | 6 | 8 | 0 |
|---|---|---|---|---|

// Dynamic programming

#### Ultra Sort

Given several sorted lists of stock prices, return a combined sorted list of all of them.

// Less efficient way that is O(m^2*n), where m is the number of lists and n is
// the average number of elements in each list.
void ultraSort(const vector<vector<double>>& stockPrices) {
  vector<double> finalSortedVector;
  vector<int> currentVectorIndices(stockPrices.size()); // Assume they start with 0
  vector<int> currentActiveVectors(stockPrices.size());
  for (int i = 0; i < stockPrices.size(); ++i) {
    currentActiveVectors.push_back(i);
  }

  unsigned int currentActiveVectorIndex;
  unsigned int currentActiveVectorMinIndex;
  unsigned int currentIndexWithinActiveVector;
  unsigned int currentMinIndexWithinActiveVector;
  double currentStockPrice;
  double currentMinStockPrice = DOUBLE_MAX;

  while (numberOfActiveVectorsLeft) {
    for(int i = 0; i < currentActiveVectors.size(); ++i) {
      currentActiveVectorIndex = currentActiveVectors[i];
      currentIndexWithinActiveVector = currentVectorIndices[currentActiveVectorIndex];
      currentStockPrice = stockPrices[i][currentIndex];
      if (currentStockPrice < currentMinStockPrice) {
        currentActiveVectorMinIndex = currentActiveVectorIndex;
        currentMinStockPrice = currentStockPrice;
      }
      currentMinIndexWithinActiveVector = currentVectorIndices[currentActiveVectorMinIndex];
    }
  }

}

#### Image Color Perimeter

Given a black and white image, represented as a multidimensional array of pixels where the color
black is 0 and the color white is 1, and particular pixel coordinate, find the perimeter of the
contiguous area occupied by the color at that pixel coordinate.

e.g.          col ---->
          0   1   2   3   4
        |---|-------|---|---|
     0  | 0 | 1   1 | 0 | 1 |     Assuming (row, col) format and 0-based indexes, pixel (3, 1)
row     |   |---|   |   |---|     contains the color 1.
 |   1  | 0   0 | 1 | 0   0 |
 |      |   |---|   |---|   |     You must find the perimeter of all of the 1's that occupy the
\|/  2  | 0 | 1   1   1 | 0 |     contiguous shape started by the first indicated 1.
        |   |   |---|   |   |
     3  | 0 | 1 | 0 | 1 | 0 |
        |---|---|---|---|---|


unsigned int perimeter(const vector<vector<int>>& image, unsigned int row, unsigned int col) {
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

bool perimeterHelper(const vector<vector<int>>& image, const vector<vector<int>>& visited,
                      unsigned int currentRow, unsigned int currentCol,
                      unsigned int& perimeter, unsigned int value)
{

}

#### Paint Bucket Tool

Assume that you have an image composed of RGB colors. You need to implement the paint bucket tool,
whereby you select a target pixel and a specific color, and fill in all the contiguous pixels
colored the same way as the target pixel. Assume the following function signature:

void fillRegion(char* image, int targetX, int targetY, char color) {

}

|---|---|---|---|---|
| 0 | 1 | 0   0 | 1 |
|   |---|       |---|
| 0   0   0   0   0 |
|   |---|---|       |
| 0 | 1   1 | 0   0 |
|   |   |---|---|   |
| 0 | 1 | 0 | 1 | 0 |
|---|---|---|---|---|


// Note that you'll need to pass in the width and height to know the bounds because this is passed
// in as a byte array and you have not enough bounds information.

#### Book Index Generator

Based on a book composed of words, generate an index of common words, followed
by a listing of all the pages that they appear on.

Notes:

(1) You are tokenizing based on words, not phrases.

(2) A word can exist multiple times on a page.

Solution:

(Ordered) hash map, mapping words to a linked list of integers, representing pages.


#### Dictionary check

Given a keyword and an array of pairs (a keyword and the page it appears in a book, where a keyword
might appear multiple times throughout the book), find the first page the given keyword appears on.

(Modification) You may not use a hash table.

(Modification) Each pair is received in a live stream (a.k.a., array changes).


// Preprocess array of pairs into hash table. O(n) time.
// Algorithm to find first instance of given keyword. O(1) time.

// Preprocess array by sorting it based on keyword, then page. O(n log n) time.
// Algorithm to find first instance of given keyword. O(log n) time.

// Insert each pair into a binary search tree of pairs. O(log n) time.
// Algorithm to find first instance of given keyword. O(log n) time.

#### Understandability Index

In order for a student to be considered as understanding a set of material in a textbook, they need to at least have read it X times. Given an ordered set of pages (or perhaps intervals), the number of times a single page must be read to be understood, and a stream of how the student read the pages (could be out of order, could be outside of the range).
[Can be done backwards or forwards. Backwards takes up more space initially, but gives you a concrete stopping point.]


[1,2,3,4,1,3,4,1,2,3,4,5,6,7,8,3,4,5,6,7]

// Reading from page 1 to numberOfPages
// pagesRead contains only the pages necessary to read
bool doesUnderstand(vector<int> pagesRead,
                    int numberOfTimesNecessaryToRead,
                    int numberOfPages) {

  if (pagesRead.size() < numberOfTimesNecessaryToRead * numberOfPages)
    return false;

  // mapping page numbers to number of times read
  unordered_map<int, int> pagesReadCounters;

  for (int i = 0; i < pagesRead.size(); ++i) {
    int currentPage = pagesRead[i];
    if (pagesReadCounters.count(currentPage) == 0) {
      pagesReadCounters[currentPage] = 1;
    } else {
      pagesReadCounters[currentPage]++;
    }
  }

  if (pagesReadCounters.size() < numberOfPages)
    return false;

  if (numberOfTimesNecessaryToRead == 1)
    return true;

  for (auto page: pagesReadCounters) {
    int numberOfTimesCurrentPageHasBeenRead = pagesReadCounters[page];
    if (numberOfTimesCurrentPageHasBeenRead < numberOfTimesNecessaryToRead)
      return false;
  }

  return true;
}

#### Prerequisite Tree

Assume a provided array of course numbers has the first course number be the course at hand and the remaining courses are its prerequisites. Say that you have an array of such arrays. Write a function that determines whether a student can take a specific course, given this array of arrays, the course desired, and all the courses the student previously took.
