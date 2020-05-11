//
// Created by Егор Назаров on 25.02.2020.
//

template <typename containerIterator, typename object>
bool noneOf(const containerIterator begin, const containerIterator end, bool (&f)(object)) {
    for (auto it = begin; it != end; it = next(it)) {
        if (f(*it)) {
            return false;
        }
    }
    return true;
}

template <typename containerIterator, typename object>
bool isSorted(const containerIterator begin, const containerIterator end, bool (&f)(object, object)) {
    containerIterator prev = begin;
    for (auto it = next(begin); it != end; it = next(it)) {
        if (!f(*prev, *it)) { // комаратор возвращает 1 еслиементы стоят правильно
            return false;
        }
        prev = it;
    }
    return true;
}

template <typename containerIterator, typename object>
object findNot(const containerIterator begin, const containerIterator end, const object v) {
    for (auto it = begin; it != end; it = next(it)) {
        if (*it != v) {
            return *it;
        }
    }
    return object();
}
