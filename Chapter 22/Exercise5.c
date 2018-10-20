
/*
Is there any difference between the printf conversion %.4d and %04d? If so, explain.

0 is ignored because we're using d (Does nothing for d, i, o, u, x, or X)
.4 is going to be the minimum number of digits (if the number is 3, it'll display 0003)
4 is the maximum number of digits (If the number is 12345, it'll display 1234)
*/
