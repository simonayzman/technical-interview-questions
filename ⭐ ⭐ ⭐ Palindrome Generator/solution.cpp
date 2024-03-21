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
