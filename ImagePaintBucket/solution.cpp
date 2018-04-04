bool paintBucket(vector<vector<int>>& image, unsigned int row, unsigned int col, targetColor) {
  if (isInBounds(image, row, col)) {
    return;
  }

  unsigned int startColor = image[row][col];
  paintBucketHelper(image, row, col, startColor, targetColor);
}

void paintBucketHelper(
  vector<vector<int>>& image,
  unsigned int currentRow,
  unsigned int currentColumn,
  unsigned int startColor,
  unsigned int targetColor
) {
  if (!isInBounds(image, currentRow, currentColumn) || image[currentRow][currentColumn] != startColor) {
    return;
  }
  image[currentRow][currentColumn] = targetColor;
  paintBucketHelper(image, currentRow-1, currentColumn, startColor, targetColor); // Up
  paintBucketHelper(image, currentRow+1, currentColumn, startColor, targetColor); // Down
  paintBucketHelper(image, currentRow, currentColumn-1, startColor, targetColor); // Left
  paintBucketHelper(image, currentRow, currentColumn+1, startColor, targetColor); // Right
}


bool isInBounds(const vector<vector<int>>& image, unsigned int row, unsigned int col) {
  return image.size() <= row || image[0].size() <= col || row == 0 || col == 0
}
