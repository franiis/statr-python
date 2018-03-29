/*
 * statr
 * Copyright (C) 2018 Piotr Krzeszewski
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file rng.h
 * @author Piotr Krzeszewski
 * @date 10 Mar 2018
 * @brief Header for internal RNG implementation.
 *
 * Header defines methods for internal generation of pseudorandom number sequences. 
 * For generating numbers from such sequences check distr.h header and presented there methods.
 * @see https://github.com/franiis/statr
 */

#ifndef RNG_H
#define RNG_H

/**
 * @brief Structure for storing RNG state. 
 * 
 * It can be used for generation of multiple pseudorandom series of data from single seed.
 * You should create this object with method RNG_state_t* create_RNG_state(unsigned int seed).
 * 
 * You should pass RNG_state_t to psudorandom methods to assure reproductability. Passing same RNG_state_t structure multiple times to pseudorandom functions allows to generate multiple number series using same seed. 
 * 
 * RNG_state_t was created to support Mersenne-Twister method. 
 */
typedef struct rng_state {
    unsigned int seed; /**< basic seed for MT pseudorandom generator */
    unsigned int *state; /**< internal state of MT generator. Should not be modified. */
    int MT_index; /**< internal data from MT generator. It's marks index in state array to be used */
} RNG_state_t;

/**
 * @brief Generates pseudorandom number based on Mersenne-Twister algorithm from uniform distribution.
 * 
 * @param state object storing state of RNG. Passing @b NULL will create random seed based on time. Frequent calling this method while passing @b NULL can generate many same numbers (based on sam seed). First call with given object or with @b NULL can take longer due to RNG state initialization. Also regeneration of RNG state is required after each 624 numbers.
 * 
 * @return Random number from uniform distribution based on passed RNG state.
 * 
 * @warning For generation numbers from uniform distribution use Instead use double runif(RNG_state_t **state, double a, double b)
 */
double unif_rand(RNG_state_t **state);

/**
 * @brief Generates pseudorandom number based on Mersenne-Twister algorithm from normal distribution.
 * 
 * @param state RNG state. For details look at double unif_rand(RNG_state_t **state)
 * 
 * @return Random number from normal distribution based on passed RNG state.
 * 
 * @warning For generation numbers from uniform distribution use Instead use double rnorm(RNG_state_t **state, double mu, double sigma)
 */
double norm_rand(RNG_state_t **state);

/**
 * @brief Creates RNG_state_t instance for storing pseudorandom generator state.
 * 
 * After calling shis method developer should call void delete_RNG_state(RNG_state_t *state), when no longer needs this object.
 * 
 * @param seed seed which will determine pseudrandom numbers sequence. Passing @b 0 will use random seed (based on time)
 * 
 * @return pointer to initialized object with set seed.
 */
RNG_state_t* create_RNG_state(unsigned int seed);

/**
 * @brief Deletes RNG_state_t object.
 * 
 * You should use this method to deallocate RNG_state_t obcect, after it's no longer needed.
 * 
 * @param state pointer to RNG_state_t object which should be deallocated.
 */
void delete_RNG_state(RNG_state_t *state);

#endif