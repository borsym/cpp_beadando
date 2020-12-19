#ifndef MAPARRAY
#define MAPARRAY
#include <map>
#include <functional>
#include <vector>
#include <algorithm>    

//clang-tidy-10 mainic6.cpp -- 2>/dev/null
//g++ -fsanitize=address,leak,undefined -O3 -Wall -Wextra -Werror mainic6.cpp


template <class Key, class Value, class Compare = std::less<Key> > 
class map_array_util
{
private:
    
    std::map<Key,Value,Compare>* point_to_map;
    typedef typename std::map<Key, Value, Compare> for_itetartor;
public:
   
    map_array_util(std::map<Key, Value, Compare> &param_map) 
    {
        point_to_map = &param_map;
    }
  
    void copy(const Value* arr, const unsigned int size)
    {                                                                                                                                            
        unsigned int i = 0;
        for(typename for_itetartor::const_iterator it = point_to_map->begin(); it != point_to_map->end() && i < size; ++it)
        {
            (*point_to_map)[it->first] = arr[i];
            ++i;
        }
    }

    bool equals(const Value* arr, const unsigned int size) const 
    {
        if((*point_to_map).size() != size) return false;   
        unsigned int i = 0;
        for(typename for_itetartor::const_iterator it = point_to_map->begin(); it != point_to_map->end(); ++it)
        {
            if((*point_to_map)[it->first] != arr[i]) return false;
            ++i;
        }

        return true;
    }
 
    void swap(const Value* arr,const unsigned int size)  
    {  
      unsigned int i = 0;
      for(typename for_itetartor::const_iterator it = point_to_map->begin(); it != point_to_map->end() && size > i; ++it)
      {
        (*point_to_map)[it->first] = arr[i];
        ++i;
      }
    }

    bool permutation(const Value* arr, const unsigned int size) const
    { 
        std::vector<Value> tmp(arr, arr + size);
        std::vector<Value> tmp2;
        for(typename for_itetartor::const_iterator it = point_to_map->begin(); it != point_to_map->end(); ++it)
           tmp2.push_back(it->second);
        
        return std::is_permutation(tmp.begin(), tmp.end(), tmp2.begin());
    }
    
    template <unsigned int n>
    map_array_util& operator=(const Value (&arr)[n])
    {
        unsigned int i = 0;
        for(typename for_itetartor::const_iterator it = point_to_map->begin(); it != point_to_map->end() && i <  n ; ++it)
        {
        (*point_to_map)[it->first] = arr[i];
            ++i;
        }

        return *this;
    }

};

#endif
