#ifndef LRU_TPP_
#define LRU_TPP_

#include "LRU.hpp"

template <typename T>
LRU<T>::LRU(std::size_t size)
    :   m_size(size),
        m_set(size) {}

template <typename T>
void LRU<T>::add(const T& val) {
    if (m_set.find(val) == m_set.end()) {
        if (m_size == m_list.size()) {
            m_set.erase(m_list.back());
            m_list.pop_back();
        }
    } else {
        m_list.erase(std::remove_if(m_list.begin(), m_list.end(), [&val](const T& m) {return m == val;}), m_list.end());
    }
    m_list.push_back(val);
    m_set.insert(val);
}

template <typename T>
void LRU<T>::display() const {
    for (const auto& i : m_list) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

template <typename T>
bool LRU<T>::get(const T& val) {
    if (m_set.find(val) != m_set.end()) {
        m_list.erase(std::find(m_list.begin(), m_list.end(), val));
        m_list.push_back(val);
        return true;
    }
    return false;
}

#endif //LRU_TPP_