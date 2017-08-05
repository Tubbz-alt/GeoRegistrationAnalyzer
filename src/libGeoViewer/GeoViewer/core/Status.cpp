/**
 * @file    Status.cpp
 * @author  Marvin Smith
 * @date    6/3/2017
 */
#include "Status.hpp"


/*********************************************/
/*      Convert Status Type to a String      */
/*********************************************/
std::string StatusTypeToString( const StatusType& status_type )
{
    switch(status_type)
    {
        case StatusType::WARNING:
            return "WARNING";
        case StatusType::FAILURE:
            return "FAILURE";
        case StatusType::SUCCESS:
            return "SUCCESS";
        default:
            return "UNKNOWN";
    }
    return "UNKNOWN";
}


/******************************************/
/*      Convert StatusType to String      */
/******************************************/
StatusType StringToStatusType( const std::string& status_type )
{
    // Failure
    if( status_type == "FAILURE" || status_type == "failure" )
    {
        return StatusType::FAILURE;
    }

    // Success
    if( status_type == "SUCCESS" || status_type == "success" )
    {
        return StatusType::SUCCESS;
    }

    // Warning
    if( status_type == "WARNING" || status_type == "warning" )
    {
        return StatusType::WARNING;
    }
    return StatusType::UNKNOWN;
}


/****************************/
/*       Constructor        */
/****************************/

