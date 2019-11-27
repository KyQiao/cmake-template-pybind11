from example_package import test
from example_package import testprint as p
# test is the class test
# and testprint is the function as defined in cpp

t3=test()
t3.testomp(100000)
f = t3.fun

t3.testomp(100000,1)
print(f(1.0))

p(f(1.1))