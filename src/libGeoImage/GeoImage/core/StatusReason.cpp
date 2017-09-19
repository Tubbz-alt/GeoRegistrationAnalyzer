/**
 * @file    StatusReason.cpp
 * @author  Marvin Smith
 * @date    6/3/2017
 */
#include "StatusReason.hpp"

namespace GEO {

/*********************************************/
/*      Convert Status Reason To String      */
/*********************************************/
std::string StatusReasonToString(const StatusReason &reason) {
    switch (reason) {
        case StatusReason::UNINITIALIZED:
            return "UNINITIALIZED";
        case StatusReason::NO_ERRORS:
            return "NO_ERRORS";
        case StatusReason::ALREADY_INITIALIZED:
            return "ALREADY_INITIALIZED";
        case StatusReason::NOT_REGISTERED:
            return "NOT_REGISTERED";
        case StatusReason::PATH_NOT_FOUND:
            return "PATH_NOT_FOUND";
        case StatusReason::GDAL_ERROR:
            return "GDAL_ERROR";
        case StatusReason::UNKNOWN_PROJECTION:
            return "UNKNOWN_PROJECTION";
        case StatusReason::NO_GEO_INFORMATION:
            return "NO_GEO_INFORMATION";
        default:
            return "UNKNOWN";
    }

    // Default to Unknown
    return "UNKNOWN";
}

} // End of GEO Namespace