// numberOfPages: Reading from page 1 to numberOfPages
// numberOfTimesNecessaryToRead: Assumed to be a minimum of 1
// pagesRead: Contains only the pages necessary to read
bool understandsExamMaterial(int numberOfPages,
                             int numberOfTimesNecessaryToRead,
                             vector<int> pagesRead) {
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

  if (pagesReadCounters.size() < numberOfPages) {
    return false;
  }

  if (numberOfTimesNecessaryToRead == 1) {
    return true;
  }

  for (auto page: pagesReadCounters) {
    int numberOfTimesCurrentPageHasBeenRead = pagesReadCounters[page];
    if (numberOfTimesCurrentPageHasBeenRead < numberOfTimesNecessaryToRead)
      return false;
  }

  return true;
}

// TODO: Solution for modification 1
