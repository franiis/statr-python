

cdef extern from "../lib/rng.h":
    struct RNG_state_t:
        pass

cdef extern from "../lib/distr.h":
    void runif(RNG_state_t **state, double a, double b)