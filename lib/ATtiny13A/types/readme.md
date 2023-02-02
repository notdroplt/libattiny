# `types/`

this folder has a very simple rewrite of the standard library, trying its best
**note that the library is called `tinystd` instead of `std`, and the headers also have a `.hpp` at the end**

## implementation status:

| header | limitations | status | 
| ------ | ----------- | ------ |
| [`<bitset`](bitset.hpp) | `N` can be at most 64 | fully implemented | 
| [`<cstdint>`](cstdint.hpp) | None | fully implemented |
| [`<iterator>`](iterator.hpp) | None | not fully implemented |
| [`<ratio>`](ratio.hpp) | None | not fully implemented |
| [`<thread>`](thread.hpp) | Only one working thread | fully implemented |
| [`<type_traits>](type_traits.hpp) | `..._v` and `..._t` members missing | almost fully implemented 