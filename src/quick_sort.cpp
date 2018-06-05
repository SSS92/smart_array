#include <smart_array.hpp>

int partition (Smart_array& array, int start, int end)
{
    int pivot = array.get_element(end);
    int i = (start - 1); 
    for (int j = start; j <= (end - 1); ++j)
    {
        if (array.get_element(j) <= pivot)
        {
            ++i;
            array.swap(i, j);
        }
    }
    array.swap((i + 1), end);
    return (i + 1);
}

void quick_sort (Smart_array& array, int start, int end)
{
    if (start < end)
    {
        int pi = partition(array, start, end);

        quick_sort(array, start, (pi - 1));
        quick_sort(array, (pi + 1), end);
    }
}

