unsigned int getPerimeter(const vector<vector<int>>& image, unsigned int row, unsigned int col) {
  if (image.size() <= row || image[0].size() <= col || row == 0 || col == 0) {
    return 0;
  }

  vector<vector<bool>> visited;
  fillWithFalse(visited);

  unsigned int runningPerimeter = 0;
  unsigned int startColor = image[row][col];
  perimeterHelper(image, visited, row, col, runningPerimeter, startColor);

  return perimeter;
}

void perimeterHelper(
  const vector<vector<int>>& image,
  const vector<vector<int>>& visited,
  unsigned int currentRow,
  unsigned int currentColumn,
  unsigned int& runningPerimeter,
  unsigned int startColor
) {

  if (!isInBounds(image, currentRow, currentColumn)) {
    return;
  }

  bool didVisit = visited[currentRow][currentColumn];
  const currentColor = image[currentRow][currentColumn];
  if (didVisit || currentColor != startColor) {
    return;
  }

  // Reaching this point means current pixel is same color as start pixel

  visited[currentRow][currentColumn] = true;

  if (!isInBounds(image, currentRow+1, currentColumn) ||
      image[currentRow+1][currentColumn] != startColor) {
    runningPerimeter += 1;
  }
  // Repeat for the other three

  perimeterHelper(image, visited, currentRow+1, currentColumn, runningPerimeter, startColor);
  // Repeat for the other three
}

bool isInBounds(const vector<vector<int>>& image, unsigned int row, unsigned int col) {
  return image.size() <= row || image[0].size() <= col || row == 0 || col == 0
}
