#include <iostream>

template <class T>
inline void print(T const &a) {
    std::cout << a << std::endl;
}


class test {
  public:
    double fun(double x);
    void testomp(const int num_steps);
    void testomp(const int num_steps, const int n);
};