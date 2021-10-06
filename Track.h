//
// Created by ker on 02/10/2021.
//

#ifndef AUTORACE_TRACK_H
#define AUTORACE_TRACK_H

#include <libqhullcpp/Qhull.h>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/random.hpp>


class Track {

    orgQhull::Qhull qh;
    boost::random::mt19937 rnd;


public:
    Track() = default;
    void GenerateTrack();
};


#endif //AUTORACE_TRACK_H
