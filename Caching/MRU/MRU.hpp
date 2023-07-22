#ifndef MRU_HPP_
#define MRU_HPP_

#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <list>

template <typename T> 
class MRU {
public:
    MRU(std::size_t);
    ~MRU() = default;
public:
    void add(const T&);
    void display() const;
    bool get(const T&);
private:
    const std::size_t m_size;
    std::list<T> m_list;
    std::unordered_set<T> m_set;
};

#include "MRU.tpp"

#endif //MRU_HPP_