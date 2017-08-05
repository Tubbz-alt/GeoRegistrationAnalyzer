/**
 * @file    Enumerations.hpp
 * @author  Marvin Smith
 * @date    4/22/2017
*/
#ifndef ENUMERATIONS_HPP
#define ENUMERATIONS_HPP

// C++ Libraries
#include <cinttypes>
#include <string>

enum class  GUI_MODE : int8_t
{
    UNKNOWN    = -1 /**< This should be an error condition.*/,
    GENERATION = 0  /**< Main Data Gathering Window.*/,
}; // End of GUI_MODE Enumeration

#endif
