#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/iostream.h>
#include <string>

template <class T>
inline void print(T const &a) {
    std::cout << a << std::endl;
}

PYBIND11_MODULE(_testprint, m) {
    m.def("testprint", &print<std::string>)
    .def("testprint", &print<int>)
    .def("testprint", &print<double>);
}