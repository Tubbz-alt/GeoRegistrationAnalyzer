/**
 * @file    StatusReason.cpp
 * @author  Marvin Smith
 * @date    6/3/2017
 */
#include "StatusReason.hpp"


/*********************************************/
/*      Convert Status Reason To String      */
/*********************************************/
std::string StatusReasonToString( const StatusReason& reason )
{
    switch(reason)
    {
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
        default:
            return "UNKNOWN";
    }

    // Default to Unknown
    return "UNKNOWN";
}
