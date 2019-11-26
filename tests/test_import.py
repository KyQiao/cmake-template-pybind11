# from test import test,testprint

# testprint.print('teast')

# import test
import ctest
import testprint
from testprint import testprint as p
from ctest import test
# from test import test as t

# print(dir(test))

# t1 = test()
# t2 = test()
# t1.testomp(100000000,4)
# t2.testomp(100000000)

print(dir(test))

t3=test()
t3.testomp(100000)
f = t3.fun

t3.testomp(100000,1)
print(f(1.0))

p(f(1.1))