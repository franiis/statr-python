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

#ifndef RNG_H
#define RNG_H

typedef unsigned int Int32;

// RNG_state_t is created for storing MT RNG state
struct rng_state {
    unsigned int seed;
    unsigned int *state; // to restore rng state set this field and MT_index to previously obtained values
    int MT_index; // it's internal MT field - you should't change it  
} typedef RNG_state_t;


// You can pass null as argument - seed and state will be generated randomly based on time. Developer will be responsible for freeing it.
// You can pass struct with *state set to null - state will be generated based on seed value (not 0)
// You can pass seed and state returned from previous unif_rand call - it will continue using the same setup.
double unif_rand(RNG_state_t **state);
double norm_rand(RNG_state_t **state);

RNG_state_t* create_RNG_state(unsigned int seed);
void delete_RNG_state(RNG_state_t *state);

#endif