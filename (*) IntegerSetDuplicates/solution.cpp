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
