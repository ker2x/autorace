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
#include <time.h>


class hull {

public:
    boost::random::mt19937 randgen;

    hull() {
        this->randgen.seed(static_cast<unsigned int>(std::time(0)));
    }

    template <class T>
    std::vector<T> generateRandomCloud(uint nbPoint, T minBound, T maxBound) {

        SDL_assert_release(minBound < maxBound);

        boost::random::uniform_real_distribution<T> rurd(minBound, maxBound);
        std::vector<T> cloud(nbPoint);
        cloud.reserve(nbPoint);

        for(auto& i: cloud) {
            cloud.push_back(rurd(randgen));
        }
        return cloud;
    }

};


#endif //AUTORACE_HULL_H
