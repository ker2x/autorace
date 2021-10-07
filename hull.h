//
// Created by ker on 07/10/2021.
//

#ifndef AUTORACE_HULL_H
#define AUTORACE_HULL_H

#include <boost/random/mersenne_twister.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/random.hpp>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/geometries.hpp>

#include <SDL.h>

#include <vector>
#include <ctime>

namespace bg = boost::geometry;
namespace bgm = boost::geometry::model;

class hull {

    boost::random::mt19937 randgen;

public:

    template <typename T>
    using point2D =  bgm::d2::point_xy<T>;

    explicit hull(const uint seed = static_cast<uint>(std::time(nullptr))) {
        this->randgen.seed(seed);
    }

    template <typename T>
    [[maybe_unused]] std::vector<T> generateRandomVector(uint nbPoint, T minBound, T maxBound) {

        SDL_assert_release(minBound < maxBound);

        boost::random::uniform_real_distribution<T> rurd(minBound, maxBound);
        std::vector<T> cloud(nbPoint);

        for(auto& i: cloud) {
            i = rurd(randgen);
        }
        return cloud;
    }



    template <typename T>
    std::vector<point2D<T>> generateRandomPointcloud(uint nbPoint, T minX, T minY, T maxX, T maxY) {

        boost::random::uniform_real_distribution<T> rurdX(minX, maxX);
        boost::random::uniform_real_distribution<T> rurdY(minY, maxY);
        std::vector<point2D<T>> cloud(nbPoint);

        for(auto& i: cloud) {
            i = {rurdX(randgen), rurdY(randgen)};
        }
        return cloud;
    }


};

#endif //AUTORACE_HULL_H
