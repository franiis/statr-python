cimport cstatr
import numpy as np
cimport numpy as np

def say_hello():
    print("Piotr - Hello")



def runif(n, min=0.0, max=1.0):
    if n == 0:
        return np.empty()

    cdef double[::1] a = np.empty(n)
    cdef double[::1] b = np.array(min)
    cdef double[::1] c = np.array(max)
    
    cstatr.runif(&a[0], n, &b[0], b.size, &c[0], c.size)
    return a
    
