#include <iostream>
#include <cstdlib>
#include <ctime>
#include "searchSortAlgorithms.h"

using namespace std;
int main()
{
    const int MAXINDEX = 10000;
    int partA[MAXINDEX];
    int partB[MAXINDEX]; /// copy of partA
    int partC[MAXINDEX]; /// copy of partA
    int partD[MAXINDEX]; /// copy of partA

    /// time objects
    clock_t startTime, endTime; /// partA array
    startTime = clock();
    srand(time(0)); /// seed rand()

    /// initialize array (unordered list)
    for (int index = 0; index < MAXINDEX; index++)
    {
       partA[index] = rand() % 100 + 1; /// values btw 1 and 100
       partB[index] = partA[index]; /// copy array elements
       partC[index] = partA[index]; /// copy array elements
       partD[index] = partA[index]; /// copy array elements
    }/// end creating array

    /// using quickSort on partA
    startTime = clock(); /// start timing
    quickSort(partA, MAXINDEX);
    endTime = clock(); /// end timing on quickSort for partA
    cout << "partA array in "
         << endTime - startTime << " time units" << endl;

    /// using quickSort2 on partB
    startTime = clock(); /// start timing
    quickSort2(partB, MAXINDEX);
    endTime = clock(); /// end timing on quicksort for partB
    cout << "partB array in "
         << endTime - startTime << " time units" << endl;

    /// using quickSort3 and insertionSort on partC
    startTime = clock(); /// start timing
    quickSort3(partC, MAXINDEX);
    endTime = clock(); /// end timing on quickSort for partC
    cout << "partC array in "
         << endTime - startTime << " time units" << endl;

    /// using quickSort4 and insertionSort on partD
    startTime = clock(); /// start timing
    quickSort4(partD, MAXINDEX);
    endTime = clock(); /// end timing on quickSort for partC
    cout << "partD array in "
         << endTime - startTime << " time units" << endl;

     return 0;
}/// end main
