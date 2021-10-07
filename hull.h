//
// Created by ker on 07/10/2021.
//

#ifndef AUTORACE_HULL_H
#define AUTORACE_HULL_H

#include <boost/random/mersenne_twister.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/random.hpp>
#include <SDL.h>
#include <vector>


class hull {

public:
    template <class T>
    static std::vector<T> generateRandomCloud(uint nbPoint, T minBound, T maxBound) {

        SDL_assert_release(minBound < maxBound);

        boost::random::mt19937 gen;
        boost::random::uniform_real_distribution<T> rurd(minBound, maxBound);
        auto generator = [&rurd, &gen](){
            return rurd(gen);
        };

        std::vector<T> cloud(nbPoint);
        cloud.reserve(nbPoint);
        std::generate(cloud.begin(), cloud.end(), generator);
        return cloud;
    }
};


#endif //AUTORACE_HULL_H
