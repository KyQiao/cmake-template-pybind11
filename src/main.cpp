#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/iostream.h>
#include <string>
#include "test.h"

template <typename... Args>
using overload_cast_ = pybind11::detail::overload_cast_impl<Args...>;

namespace py = pybind11;

// need to be same with CMakelist module name
PYBIND11_MODULE(ctest, m) {
    py::class_<test>(m, "test")
    .def(py::init<>())
    .def("testomp", overload_cast_<int>()(&test::testomp))
    .def("testomp", overload_cast_<int, int>()(&test::testomp))
    .def("fun", &test::fun)
    .def("testprint", &print<std::string>)
    .def("testprint", &print<int>)
    .def("testprint", &print<double>);;

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "0.0.1";
#endif
}

// this
PYBIND11_MODULE(testprint, m) {
    m.def("testprint", &print<std::string>)
    .def("testprint", &print<int>)
    .def("testprint", &print<double>);
}