#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 20
#define MAX_SUBSETS 1048576 // 2^20 maximum possible subsets

// Structure to hold a subset of integers
typedef struct {
    int data[MAX_ELEMENTS];
    int size;
} Subset;

// Global array to store all valid subsets found during backtracking
Subset allResults[MAX_SUBSETS];
int resultCount = 0;

// Temporary array to hold the current path/subset
int currentSubset[MAX_ELEMENTS];
int currentSize = 0;

// Recursive backtracking function to find all valid subsets
void findSubsets(int index, int currentSum, int targetSum, int* elements, int n) {
    // Base Case: If we have processed all elements
    if (index == n) {
        if (currentSum == targetSum) {
            // Save the valid subset to our results collection
            allResults[resultCount].size = currentSize;
            for (int i = 0; i < currentSize; i++) {
                allResults[resultCount].data[i] = currentSubset[i];
            }
            resultCount++;
        }
        return;
    }

    // Choice 1: Include the current element
