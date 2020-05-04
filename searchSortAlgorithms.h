template <class elemType>
void insertionSort(elemType list[], int length) /// O(n^2) a little faster
{
    for (int firstOutOfOrder = 1; firstOutOfOrder < length;
                                  firstOutOfOrder++)
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
        {
            elemType temp = list[firstOutOfOrder];
            int location = firstOutOfOrder;

            do
            {
                list[location] = list[location - 1];
                location--;
            } while(location > 0 && list[location - 1] > temp);

            list[location] = temp;
        }
} //end insertionSort

template <class elemType>
void swap(elemType list[], int first, int second)
{
    elemType temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
} //end swap

template <class elemType>
int partition(elemType list[], int first, int last)
{
    elemType pivot;

    int index, smallIndex;

    swap(list, first, (first + last) / 2);

    pivot = list[first];
    smallIndex = first;

    for (index = first + 1; index <= last; index++)
        if (list[index] < pivot)
        {
            smallIndex++;
            swap(list, smallIndex, index);
        }

    swap(list, first, smallIndex);

    return smallIndex;
} //end partition

///partition using the median of first, middle, and last elements
template <class elemType>
int partition2(elemType list[], int first, int last)
{
    elemType pivot;

    int index, smallIndex;

    int mid = (first + (last - first) + last) / 3;

    pivot = list[mid];
    smallIndex = first;

    for (index = first + 1; index <= last; index++)
        if (list[index] < pivot)
        {
            smallIndex++;
            swap(list, smallIndex, index);
        }

    swap(list, first, smallIndex);

    return smallIndex;
} //end partition2

template <class elemType>
void recQuickSort(elemType list[], int first, int last)
{
    int pivotLocation;

    if (first < last)
    {
        pivotLocation = partition(list, first, last);
        recQuickSort(list, first, pivotLocation - 1);
        recQuickSort(list, pivotLocation + 1, last);
    }
} //end recQuickSort

template <class elemType>
void recQuickSort2(elemType list[], int first, int last)
{
    int pivotLocation;

    if (first < last)
    {
        pivotLocation = partition2(list, first, last);
        recQuickSort2(list, first, pivotLocation - 1);
        recQuickSort2(list, pivotLocation + 1, last);
    }
} //end recQuickSort2

///for partA
template <class elemType>
void quickSort(elemType list[], int length) /// O(n * log n)
{
    recQuickSort(list, 0, length - 1);
} //end quickSort

///for partB
template <class elemType>
void quickSort2(elemType list[], int length) /// O(n * log n)
{
    recQuickSort2(list, 0, length - 1);
} //end quickSort2

///for partC
template <class elemType>
void quickSort3(elemType list[], int length) /// O(n * log n)
{
    int i;

    for (int i = 0; i <= 20; i++)
    {
    recQuickSort(list, 0, length - 1);
    }

    insertionSort(list, length - 1);
} //end quickSort2

/// for partD
template <class elemType>
void quickSort4(elemType list[], int length) /// O(n * log n)
{
    int i;

    for (int i = 0; i <= 20; i++)
    {
    recQuickSort2(list, 0, length - 1);
    }

    insertionSort(list, length - 1);
} //end quickSort2
