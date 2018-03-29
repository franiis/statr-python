

cdef extern from "../lib/rng.h":

    ctypedef struct RNG_state_t:
        pass

    RNG_state_t* create_RNG_state(unsigned int seed)
    void delete_RNG_state(RNG_state_t *state)
    

cdef extern from "../lib/distr.h":
    double runif(RNG_state_t **state, double a, double b)