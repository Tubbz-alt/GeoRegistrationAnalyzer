/**
 * @file    Status_Reason.hpp
 * @author  Marvin Smith
 * @date    6/3/2017
 */
#ifndef CORE_STATUS_REASON_HPP
#define CORE_STATUS_REASON_HPP


// C++ Libraries
#include <cinttypes>
#include <string>


/**
 * @enum CoreStatusReaon
 * @brief General-Purpose reason for a failure
 */
enum class CoreStatusReason : int16_t
{
        UNKNOWN = 0 /**< This is a good error condition.*/,
        NO_ERRORS = 1 /**< No errors detected.*/,
        UNINITIALIZED = 2 /**< Something not initialized or allocated properly.*/,
};


/**
 * @brief Convert Status Reason to String
 */
std::string StatusReasonToString( );


#endif