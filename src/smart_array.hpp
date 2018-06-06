#include <iostream>
#include <cstddef>
#ifndef SMART_ARRAY_HPP
#define SMART_ARRAY_HPP

class Smart_array
{
    private: 
        int m_size;
        int* m_array;
        int m_default_value;
        
        /**
         *@brief  Initializes the smart array whith the given array  
         *@param  Pointer to an array, count of the array elements 
         */
        void init_array (int* array, unsigned int count);

        /**
         *@brief  Checkes inserted index out of range or not
         *@param  index of an array's element
         *@return False if inserted index is out of range, true - otherwise 
         */
        bool is_out_of_range (int i) const;

        /**
         *@brief  Creates an array and initializes it with default value
         *@param  Size of the array
         *@return Pointer to the created array
         */
        int* create_array (unsigned int size, bool init = true);

     public:
        
        /**
         *@brief  Smart_array's constructor: creates an array with a given size, 
                   if array is not null and count > 0, it initializes the array with the given array elements.
                   If the size of given array > the size of created array, then it set the size to new one.
         *@param  size of the array
         *@param  array for initializing the smart array(optional).
         *@param  count of the given array's elements(required if array is provided).
         */
        Smart_array (unsigned int size, int default_value, int* array = NULL, unsigned int count = 0);
        
        /**
         *@brief Smart_array's copy constructor
         *@param is an Smart_array type variable
         */
        Smart_array(const Smart_array &array);

        /**
         *@brief  Returns the array size
         *@return Array's size 
         */
        int get_size (void);

        /**
         *@brief Returns array's i-th element
         *@param The index of an array element
         *@return int MAX_VALUE if the index is out of range, else returns array's element by index  
         */
        int get_element (int i) const;

        /**
         *@brief  Changes array's i-th element value to passed one
         *@param  index of array's elements
         *@param  new value
         *@return False if inserted index is out of range, else set inserted element by index  
         */
        bool set_element (int i, int v);

        /**
         *@brief  Swaps arrays elements by given indexes
         *@param  first index
         *@param  second index
         *@return False if one of inserted indexes is out of range. True - otherwise
         */
        bool swap(int i, int j); 
        
        /**
         *@brief  Creates new array with given size, initializes it, replaces existing array with new one
         *@param  Size of a new array
         *@return False if new size is equal to existing size. True - otherwise
         */
        bool resize (int size);
         
        Smart_array & operator = (const Smart_array &s);

        int& operator [](int i);

        int operator [] (int i) const;

        friend std::ostream& operator << (std::ostream & os, const Smart_array & a);  
        
        friend std::istream& operator >> (std::istream & input, Smart_array & a);          
       
        /**
         *@brief Prints the array
         **/ 
        void print () const;
        
        /**
         * @brief Smart_array's destructor, deletes allocated memory 
        **/ 
        ~Smart_array ();
};

#endif
