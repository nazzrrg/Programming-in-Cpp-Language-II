//
// Created by Егор Назаров on 25.02.2020.
//

template <typename container>
bool noneOf(const container&, bool);
template <typename container>
bool isSorted(const container&, bool);
template <typename container, typename object>
object& findNot(const container&, const object&);
template <typename containerIterator>
bool noneOf(containerIterator, containerIterator, bool);
template <typename containerIterator>
bool isSorted(containerIterator, containerIterator, bool);
template <typename containerIterator, typename object>
object& findNot(containerIterator, containerIterator, const object&);

#include "common.tpp"

