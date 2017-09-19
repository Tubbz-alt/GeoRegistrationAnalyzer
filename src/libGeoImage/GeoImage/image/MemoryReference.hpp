/**
 * @file    MemoryReference.hpp
 * @author  Marvin Smith
 * @date    9/17/2017
 */
#ifndef LIB_GEO_IMAGE_IMAGE_MEMORY_REFERENCE_HPP
#define LIB_GEO_IMAGE_IMAGE_MEMORY_REFERENCE_HPP

// C++ Libraries
#include <cinttypes>
#include <memory>
#include <string>


namespace GEO{


class MemoryReferenceBase
{
    public:

        virtual uint8_t* Get_Buffer() 
};



} // End of GEO Namespace

#endif