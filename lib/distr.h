#ifndef DISTR_H
#define DISTR_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "math.h"
#include "rng.h"

double runif(RNG_state_t **state, double a, double b);

double rnorm(RNG_state_t **state, double mu, double sigma);


#endif