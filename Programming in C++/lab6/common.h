//
// Created by Егор Назаров on 25.02.2020.
//
#ifndef LAB4_COMMON_H
#define LAB4_COMMON_H

template <typename containerIterator>
bool noneOf(containerIterator, containerIterator, bool);
template <typename containerIterator>
bool isSorted(containerIterator, containerIterator, bool);
template <typename containerIterator, typename object>
object findNot(containerIterator, containerIterator, object);

#include "common.tpp"

#endif