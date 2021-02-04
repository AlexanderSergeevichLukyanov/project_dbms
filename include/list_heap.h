#include <cassert>
#include <cmath>
#include <functional>
#include <list>
#include <type_traits>
#include <utility>
template <typename T, typename Compare = std::less<T>>
struct list_heap {
private:
    std::list<T> list_for_heap;
    typename std::list<T>::iterator iter_min;
    Compare comp;

public:
    // Default copying is not good enough: the copied iterator should point to
    // the copied list, not the original one. Do not modify following five
    // lines.
    // list_heap(/const Compare &compare = Compare()*/) : comp(compare){};
    list_heap() = default;
    explicit list_heap(const Compare &compare) : comp(compare){};
    list_heap(const list_heap &) = delete;
    list_heap &operator=(const list_heap &) = delete;
    list_heap(list_heap &&) noexcept = default;
    list_heap &operator=(list_heap &&) noexcept = default;
    ~list_heap() = default;

    [[nodiscard]] int size() const {
        return list_for_heap.size();
    }

    [[nodiscard]] bool empty() const {
        return list_for_heap.empty();
    }

    void push(const T &value) {
        list_for_heap.push_back(value);

        if (list_for_heap.size() == 1 || comp(value, *iter_min)) {
            iter_min = --list_for_heap.end();
        }
    }

    [[nodiscard]] const T &top() const {
        assert(!empty());
        return *iter_min;
    }

    void merge(list_heap &other) {
        if (other.empty()) {
            return;
        }
        if (empty() || comp(*(other.iter_min), *iter_min)) {
            iter_min = other.iter_min;
        }
        list_for_heap.splice(list_for_heap.end(), other.list_for_heap);
    }

    void pop() {
        list_for_heap.erase(iter_min);
        if (empty()) {
            return;
        }
        iter_min = list_for_heap.begin();
        for (auto iter = list_for_heap.begin(); iter != list_for_heap.end();
             ++iter) {
            if (comp(*iter, *iter_min)) {
                iter_min = iter;
            }
        }
    }
};
