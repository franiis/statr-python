import numpy as np
cimport numpy as np
cimport cstatr as cs

cpdef say_hello():
    print("Piotr - Hello")

cpdef runif(n, min=0.0, max=1.0):
    if n == 0:
        return np.empty()
    
    #cstatr.runif(&a[0], n, &b[0], b.size, &c[0], c.size)
    a = cs.runif(NULL, 0, 1)
    return a
    
