#include <smart_array.hpp>
#include <iostream>
#include <new>
#include <cassert>
#include <limits>   

void Smart_array::init_array (int* array, unsigned int count) 
{               
    assert(array);
    for (int i = 0; i < count; ++i) { 
        assert((m_array + i)); 
        m_array[i] = array[i];
    }
}

bool Smart_array::is_out_of_range (int i) const
{
    if (i < 0 || i >= m_size) {
        return true;
    }
    return false;
}

int* Smart_array::create_array (unsigned int size, bool init)
{
    int* array;
    try {
        array = new int[size];
    }
    catch (std::bad_alloc &e) {
        std::cout << e.what() << std::endl;
        m_size = 0;
        return 0;
    }
    if (!init) {
         return array;
    } 
    for (int j = 0; j < size; ++j) {
        array[j] = m_default_value;
    }
    return array;
}

Smart_array::Smart_array (unsigned int size, int default_value, int* array, unsigned int count)
{
    std::cout << "constructor called" << std::endl; 
    if (array && count > 0) {
        if (count > size) {
            size = count;
        }
    }
    m_size = size;
    m_default_value = default_value;
    m_array = create_array(m_size);
    if (array && count > 0) {
        init_array(array, count);
    }
}

Smart_array::Smart_array(const Smart_array &array) 
{    
    std::cout << " copy constructor called" << std::endl;                           
    m_size = array.m_size;
    m_default_value = array.m_default_value;
    m_array = create_array(m_size, false);
    for (int i = 0; i < m_size; ++i) {
        m_array[i] = array.get_element(i);
    }
}

int Smart_array::get_size (void) 
{
    return m_size;
}

int Smart_array::get_element (int i) const
{
    if (is_out_of_range(i)) {
        return std::numeric_limits<int>::max();
    }
    assert((m_array + i));
    return m_array[i];
}

bool Smart_array::set_element (int i, int v) 
{    
    if (is_out_of_range(i)) {
        return false;
    } 
    assert((m_array + i)); 
    m_array[i] = v;
    return true;
    
}

bool Smart_array::swap(int i, int j)
{   
    if (!is_out_of_range(i) && !is_out_of_range(j)) {
        assert((m_array + i));
        assert((m_array + j)); 
        int buffer = m_array[i];
        m_array[i] = m_array[j];
        m_array[j] = buffer;
        return true;
    }
    return false;
}    

bool Smart_array::resize (int size) 
{
    if (size != m_size) { 
        int* new_array = create_array(size);
        int count = (size > m_size)? m_size: size;
        for (int i = 0; i < count; ++i) {
            assert((m_array + i));
            new_array[i] = m_array[i];
        }
        delete [] m_array;
        m_array = new_array;
        m_size = size;
        return true;
    }
    return false;
}

Smart_array & Smart_array::operator = (const Smart_array &s) {
    if (this == &s) { 
        return *this;
    }
    int* new_array = create_array(s.m_size, false);
    for (int i = 0; i < s.m_size; ++i) {
        assert((s.m_array + i));
        new_array[i] = s.m_array[i];
    }
    m_size = s.m_size;
    m_default_value = s.m_default_value;
    delete [] m_array;
    m_array = new_array; 
}

void Smart_array::print ()
{
    for (int i = 0; i < m_size; ++i) {
        assert((m_array + i));
        std::cout << m_array[i] << ", ";
    }
    std::cout << std::endl;
}

Smart_array::~Smart_array () 
{
    std::cout << "destructor called" << std::endl;
    delete [] m_array;
}

