#include <smart_array.hpp>
#include <quick_sort.hpp>
#include <iostream>

int main () 
{
     int arr[4] = {81, 32 , 447, 8};
     Smart_array A(10, -1, arr, 4);
     A.print();
     A.set_element(4, 16);
     A.set_element(5, 3);   
     A.print();
     A.swap(0, 1);
     A.print();
     std::cout << A.get_element(4) << std::endl;
     Smart_array B = A;
     quick_sort(A, 0, 9);
     A.print();
     B.print();
     Smart_array C(1, -2);
     C.print();
     C = B;
     C.set_element(0, 88);
     C.print();
     std::cout << C[1] << std::endl;
     C[1] = 87556;
     C.print();
     const Smart_array D = C;
     std::cout << D[1] << std::endl;
     std::cout << std::endl;
     std::cout << std::endl;
     std::cout << std::endl;
     (C[1] = C[2]) = C[3];
     C.print();
     std::cout << std::endl << std::endl;
     D.print();
     std::cout << D;
     std::cin >> C;
     std::cout << C;
     return 0;
} 
