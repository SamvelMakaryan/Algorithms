#ifndef LRU_HPP_
#define LRU_HPP_


#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <list>

template <typename T> 
class LRU {
public:
    LRU(std::size_t);
    ~LRU() = default;
public:
    void add(const T&);
    void display() const;
    bool get(const T&);
private:
    const std::size_t m_size;
    std::list<T> m_list;
    std::unordered_set<T> m_set;
};

#include "LRU.tpp"
#endif //LRU_HPP_