In this program, I have implemented the Thomas Algorithm to calculate
Ax=b 
for a sparse matrix in order to save memory and optimize calculations. I did not create additional vectors (such as a n[] vector), but instead utilized existing ones for optimization

                                    | 10 1/2                          |        |30     |
                                    |  1/3 20  1/4                    |        |165/4  |
                                    |      1/5  30  1/6               |  *     |917/30 |
                                    |           1/7 30   1/8          |        |851/28 |
                                    |                1/9  20   1/10   |        |3637/90| 
                                    |                     1/11  10    |        |332/11 |
                                    A matrix                                    b vector
