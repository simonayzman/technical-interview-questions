### Image Perimeter

Given a black and white image, represented as a multidimensional array of pixels where the color black is 0 and the color white is 1, and particular pixel coordinate, find the perimeter of the contiguous area occupied by the color at that pixel coordinate.

```
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
```

\[[Solution](solution.cpp)\]
