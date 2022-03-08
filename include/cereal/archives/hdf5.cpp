//
// Created by kris on 6/15/18.
//
#include "hdf5.hpp"

namespace cereal {


/*
template<class T>
void prologue(HDF5OutputArchive& ar, T const &)
{
    std::cout << "111" << std::endl;
}
*/

template<typename T>
void prologue(HDF5OutputArchive& ar, T const &)
{
    std::cout << "222" << std::endl;
}

} // End namespace cereal