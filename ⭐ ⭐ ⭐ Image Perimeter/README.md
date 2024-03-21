### Image Perimeter

Given a black and white image, represented as a multidimensional array of pixels where the color black is 0 and the color white is 1, and particular pixel coordinate, find the perimeter of the contiguous area occupied by the color at that pixel coordinate.

```
              col ---->

            0   1   2   3   4
          |---|-------|---|---|
       0  | 0 | 1   1 | 0 | 1 |
row       |   |---|   |   |---|
 |     1  | 0   0 | 1 | 0   0 |
 |        |   |---|   |---|   |
\|/    2  | 0 | 1   1   1 | 0 |
          |   |   |---|   |   |
       3  | 0 | 1 | 0 | 1 | 0 |
          |---|---|---|---|---|
```

\[[Solution](solution.cpp)\]
