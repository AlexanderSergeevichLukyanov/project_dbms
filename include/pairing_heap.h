#include <cassert>
#include <cmath>
#include <functional>
#include <list>
#include <type_traits>
#include <utility>
template <typename T, typename Compare = std::less<T>>
struct list_heap {
};