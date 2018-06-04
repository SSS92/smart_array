class Smart_array
{
    private: 
        int m_size;
        float* m_array;
        float default_value = 1.5;
        
        void init_array (int* array = NULL, unsigned int count = 0);

        bool is_out_of_range (int i);

        /**
         * @brief Creates an array and initializes it with default value
         * @param Size of the array
         */
        float* create_array (unsigned int size);

     public:
        
        /**
         * @brief  Smart_array's constructor: creates an array with a given size, 
                   if array is not null and count > 0, it initializes the array with the given array elements.
                   If the size of given array > the size of created array, then it set the size to new one.
         * @param  size of array
         * @param  already created array is initialized with passed one's elements.
         * @param  count of the given array's elements.
        **/
        Smart_array (unsigned int size, int* array = NULL, unsigned int count);
        
        /**
         *  @brief Smart_array's copy constructor
         *  @param is an Smart_array type variable
        **/
        Smart_array(const Smart_array &array);

        /**
         * @brief Returns the array size
        **/
        int get_size (void);

        /**
         * @brief Returns array's i-th element
         * @param The index of an array element
        **/
        int get_element (int i);

        /**
         * @brief Changes array's i-th element value to passed one
         * @param index of array's elements
         * @param new value
        **/
        void set_element (int i, int v);

        /**
         * @brief Creates new array with given size, initializes it, replaces existing array with new one
         * @param Size of a new array 
        **/
        void resize (int size);
         
        /**
         * @brief Prints the array
         **/ 
        void print ();
        
        /**
         * @brief Smart_array's destructor, deletes allocated memory 
        **/ 
        ~Smart_array ();
}
