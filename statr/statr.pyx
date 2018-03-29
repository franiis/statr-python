import numpy as np
cimport numpy as np
cimport cstatr as cs

cpdef say_hello():
    print("Piotr - Hello")

cpdef runif(n, a=0.0, b=1.0):
    if n == 0:
        return np.empty()
    
    res = np.zeros(n)

    cpdef RNG_state_t *state = cs.create_RNG_state(10)

    for i in range(0, n):
        res[i] = cs.runif(&state, a, b)

    cs.delete_RNG_state(state)

    return res
    
