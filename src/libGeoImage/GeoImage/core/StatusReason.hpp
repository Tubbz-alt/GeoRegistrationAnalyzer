/**
 * @file    Status_Reason.hpp
 * @author  Marvin Smith
 * @date    6/3/2017
 */
#ifndef LIB_GEO_IMAGE_CORE_STATUS_REASON_HPP
#define LIB_GEO_IMAGE_CORE_STATUS_REASON_HPP


// C++ Libraries
#include <cinttypes>
#include <string>

namespace GEO {

/**
 * @enum CoreStatusReaon
 * @brief General-Purpose reason for a failure
 */
enum class StatusReason : int16_t {
        UNKNOWN = 0 /**< This is a good error condition.*/,
        NO_ERRORS = 1 /**< No errors detected.*/,
        UNINITIALIZED = 2 /**< Something not initialized or allocated properly.*/,
        ALREADY_INITIALIZED = 3 /**< Already Initialized.*/,
        NOT_REGISTERED = 4 /**< No Matching Objects Registered.*/,
        PATH_NOT_FOUND = 5 /**< No path found on system.*/,
        GDAL_ERROR = 6 /**< Error with GDAL Processing.*/,
        UNKNOWN_PROJECTION = 7 /**< Unknown or unsupported projection type.*/,
        NO_GEO_INFORMATION = 8 /**< Missing Geo-Information*/,
};


/**
 * @brief Convert Status Reason to String
 */
std::string StatusReasonToString(const StatusReason &reason);

} // End of GEO Namespace

#endif