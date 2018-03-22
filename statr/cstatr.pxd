

cdef extern from "lib/distr/distr.h":
    void runif(double *res, int nres, double *a, int na, double *b, int nb)