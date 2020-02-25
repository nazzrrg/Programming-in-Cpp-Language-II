//
// Created by Егор Назаров on 25.02.2020.
//
#ifndef LAB6_COMMON_H
#define LAB6_COMMON_H

template <typename containerIterator, typename object>
bool noneOf(containerIterator, containerIterator, bool (&f)(object));
template <typename containerIterator, typename object>
bool isSorted(containerIterator, containerIterator, bool (&f)(object, object));
template <typename containerIterator, typename object>
object findNot(containerIterator, containerIterator, object);

#include "common.tpp"

#endif