//
// Created by Егор Назаров on 25.02.2020.
//

template <typename container>
bool noneOf(const container& c, bool (&f)(int)) {
    for (auto& x : c) {
        if (f(x)) {
            return false;
        }
    }
    return true;
}

template <typename container>
bool isSorted(const container& c, bool (&f)(int)) {
    bool was = false;
    for (auto& x : c) {
        if (f(x)) {
            was = true;
        } else if (was) {
            return false;
        }
    }
    return true;
}

template <typename container, typename object>
object& findNot(const container& c, object& v) {
    for (auto x : c) {
        if (x != v) {
            return x;
        }
    }
    return object();
}

template <typename containerIterator>
bool noneOf(containerIterator begin, containerIterator end, bool (&f)(int)) {
    for (auto it = begin; it != end; it = next(it)) {
        if (f(*it)) {
            return false;
        }
    }
    return true;
}

template <typename containerIterator>
bool isSorted(containerIterator begin,containerIterator end, bool (&f)(int)) {
    bool was = false;
    for (auto it = begin; it != end; it = next(it)) {
        if (f(*it)) {
            was = true;
        } else if (was) {
            return false;
        }
    }
    return true;
}

template <typename containerIterator, typename object>
object& findNot(containerIterator begin, containerIterator end, object& v) {
    for (auto it = begin; it != end; it = next(it)) {
        if (*it != v) {
            return *it;
        }
    }
    return object();
}