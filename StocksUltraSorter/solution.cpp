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

// TODO: More efficient solution that is O(m * n * log m) determines max using a priority queue
