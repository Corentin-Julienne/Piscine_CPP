# Implementation of a Ford-Johnson Merge Insertion Algorithm (with std::vector and std::deque)

## Global explanation

### phase 1

If there is an odd number of values, we just pop the last value and store it in a Class variable

### phase 2

We need to store the values in pairs of ints instead of sorting it by ints. So , if a vector contains 4 ints, it will be 2 pairs (first pair of index 0 and 2, second pairs composed of indexes 2 and 3).

### phase 3

Sort every pair (the greater int will be first and the lesser will be second)

### phase 4

Sort all pairs based on first (the greater int of each pair). so vector of [4, 5] and [2, 3] will be [2, 3], [4, 5]

### phase 5

Extract all highest members of every pair and put then in a output data structure

### phase 6

Extract all lowest members of every pair and put them in a pend data structure

### phase 7



### phase 8



### phase 9

Insert the last odd number previously stored (if necessary)