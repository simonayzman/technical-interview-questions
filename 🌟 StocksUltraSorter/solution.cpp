// Less efficient way that is O(m^2 * n), where m is the number of lists and n is
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

// More efficient solution that is O(m * n * log m) determines max using a priority queue
void ultraSort(const list<list<double>>& stockPrices) {
  priority_queue<pair<int, double>> priorityQ(sortByStockPriceInPair); // assume exists
  vector<double> finalSortedVector;
  
  // Initialization step
  for (int i = 0; i < stockPrices.size(); ++i) {
    vector<double>& currentStockPricesList = stockPrices[i];
    pair<int, double> startEntry = create_pair(i, currentStockPricesList.front());
    priorityQ.push(startEntry);
  }

  // O(m * n)
  while (!priorityQ.empty()) {
    pair<int, double> currentEntry = priorityQ.pop();
    int vectorIndex = currentEntry.getFirst();
    double stockPrice = currentEntry.getSecond();
    vector& currentStockPricesList = stockPrices[vectorIndex];
    currentStockPricesList.popFront();
    finalSortedVector.push(stockPrice);

    // O(log m)
    if (!currentStockPricesList.empty()) {
      double nextValue = currentStockPricesList.top();
      pair<int, double> nextEntry = create_pair(vectorIndex, nextValue);
    }
  }

  return finalSortedVector;
}