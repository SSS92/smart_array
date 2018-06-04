#include <smart_array.hpp>
#include <iostream>
#include <new>

        
void Smart_array::init_array (int* array = NULL, unsigned int count = 0) 
{
    for (int i = 0; i < count; ++i) {
        this.m_array[i] = array[i];
    }
}

bool Smart_array::is_out_of_range (int i) 
{
    if (i < 0 || i >= this.m_size) {
        return true;
    }
    return false;
}

float* Smart_array::create_array (unsigned int size)
{
    try {
        float* array = new float[size];
    }
    catch (std::bad_alloc &e) {
        std::cout << e.what() << std::endl;
        this.m_size = 0;
        return 0;
    } 
    for (int j = 0; j < size; ++j) {
        array[j] = this.default_value;
    } 
    return array;
}

Smart_array::Smart_array (unsigned int size, int* array = NULL, unsigned int count)
{
    if (array && count > 0) {
        if (count > size) {
            size = count;
        }
    }
    this.m_size = size;
    this.m_array = this.create_array(this.m_size);
    if (array && count > 0) {
        this.init_array(array, count);
    }
}

Smart_array::Smart_array(const Smart_array &array) 
{
    m_size = array.m_size; 
    m_array = array.m_array; 
}

int Smart_array::get_size (void) 
{
    return this.m_size;
}

int Smart_array::get_element (int i)
{
    if (this.is_out_of_range(i)) {
        std::cout << i << " is out of range" << std::endl;
        return 0;
    }
    return this.m_array[i];
}

void Smart_array::set_element (int i, int v) 
{
    if (this.is_out_of_range(i)) {
        std::cout << i << " is out of range" << std::endl;
    } else {
        this.m_array[i] = v;
    }
}

void Smart_array::resize (int size) 
{
    float* new_array = this.create_array(size);
    for (int i = 0; i < size; ++i) {
        new_array[i] = this.m_array[i];
    }
    delete [] this.m_array;
    this.m_array = new_array;
    this.m_size = size;
}

void Smart_array::print ()
{
    for (int i = 0; i < this.m_size; ++i) {
        std::cout << this.m_array[i] << ", ";
    }
    std::cout << std::endl;
}

Smart_array::~Smart_array () 
{
    delete [] this.m_array;
}

