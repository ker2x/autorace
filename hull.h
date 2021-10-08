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

    /***
     * Constructor with a default random seed based on current time.
     * @param seed a uint seed for the random generator.
     */
    explicit hull(const uint seed = static_cast<uint>(std::time(nullptr))) { // NOLINT(clion-misra-cpp2008-18-0-4)
        this->randgen.seed(seed);
    }


    /***
     * Generate a 1 dimension vector of uniformly distributed point.
     * @tparam T usually int, uint, float, or double
     * @param nbPoint how many point to generate for the vector
     * @param minBound minimum bound (included)
     * @param maxBound maximum bound (excluded)
     * @return a vector of uniformly distributed point.
     */
    template <typename T>
    [[maybe_unused]] [[nodiscard]]
    std::vector<T> generateRandomVector(uint nbPoint, T minBound, T maxBound) noexcept {

        boost::random::uniform_real_distribution<T> rurd(minBound, maxBound);
        std::vector<T> cloud(nbPoint);

        for(auto& i: cloud) {
            i = rurd(randgen);
        }
        return cloud;
    }


    /***
     * Generate a 2D cloud of uniformly distributed point_xy
     * @tparam T usually int, float, or double
     * @param nbPoint how many point to generate for the cloud
     * @param minX minimum bound for X (included)
     * @param minY minimum bound for Y (included)
     * @param maxX maximum bound for X (excluded)
     * @param maxY maximum bound for Y (excluded)
     * @return a vector of 2D point_xy
     */
    template <typename T>
    [[nodiscard]] [[maybe_unused]]
    std::vector<point2D<T>> generateRandomPointcloud(uint nbPoint, T minX, T minY, T maxX, T maxY) noexcept {

        boost::random::uniform_real_distribution<T> rurdX(minX, maxX);
        boost::random::uniform_real_distribution<T> rurdY(minY, maxY);
        std::vector<point2D<T>> cloud(nbPoint);

        for(auto& i: cloud) {
            i = {rurdX(randgen), rurdY(randgen)};
        }
        return cloud;
    }

    //https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/
    template <typename T>
    [[nodiscard]] [[maybe_unused]]
    std::vector<point2D<T>> convexHullFromPoint2D(std::vector<point2D<T>> cloud) noexcept {

        // Initialize Result
        std::vector<point2D<T>> convexHull;

        // There must be at least 3 points
        if(cloud.size() < 3) {
            return convexHull; // return an empty hull for now until I find a better solution. (Optional?)
        }

        // Find the leftmost point (tested, it seems to work)
        point2D<float> leftmostPoint = cloud.front();
        for(auto p: cloud) {
            if(p.x() < leftmostPoint.x()) {
                leftmostPoint = p;
            }
        }
        convexHull.push_back(leftmostPoint);

        // Start from leftmost point, keep moving counterclockwise
        // until reach the start point again.  This loop runs O(h)
        // times where h is number of points in result or output.


        // return points making the convex hull
        return convexHull;
    }

};

#endif //AUTORACE_HULL_H
