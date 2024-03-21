### Paint Bucket Tool

Assume that you have an image composed of RGB colors. You need to implement the paint bucket tool, whereby you select a target pixel and a specific color, and fill in all the contiguous pixels colored the same way as the target pixel.

```
              col ---->
              
            0   1   2   3   4
          |---|-------|---|---|
       0  | 0 | 3 | 0 | 2 | 4 |
row       |   |---|   |   |---|
 |     1  | 0   0   0 | 2   2 |
 |        |   |---|---|       |
\|/    2  | 0 | 1   1 | 2   2 |
          |   |   |---|---|   |
       3  | 0 | 1 | 0 | 1 | 2 |
          |---|---|---|---|---|
          
Assuming (row, col) format and 0-based indexes, pixel (3, 1) contains the color 1.
```

\[[Solution](solution.cpp)\]
