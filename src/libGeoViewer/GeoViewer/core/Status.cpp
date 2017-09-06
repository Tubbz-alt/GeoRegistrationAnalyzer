/**
 * @file    Status.cpp
 * @author  Marvin Smith
 * @date    6/3/2017
 */
#include "Status.hpp"

// C++ Libraries
#include <sstream>


// Project Libraries
#include "StatusReason.hpp"

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
Status::Status()
 : m_class_name("Status"),
   m_status_type(StatusType::FAILURE),
   m_status_reason(StatusReason::UNINITIALIZED),
   m_status_details("Not Initialized"),
   m_status_appended(false)
{

}


/****************************/
/*       Constructor        */
/****************************/
void Status::Append( const StatusType&    status_type,
                     const StatusReason&  status_reason,
                     const std::string&   status_details )
{
    Append( Status( status_type,
                    status_reason,
                    status_details));
}


/********************************/
/*       Append to Status       */
/********************************/
void Status::Append(const Status &new_status)
{
    // Decision Matrix
    //
    //  Current StatusType  |   New StatusType  |  Action                | Covered By If/Else Stmt
    //        SUCCESS       |      SUCCESS      |  Nothing               |  1
    //        SUCCESS       |  WARNING/FAILURE  |  Replace               |  2
    //        FAILURE       |      SUCCESS      |  Nothing               |  1
    //        WARNING       |      FAILURE      |  Replace / Append Old  |  3
    //        FAILURE       |      WARNING      |  Append New            |  4

    // Stmt 1 : If new status is success, ignore completely
    if( new_status.Get_Status_Type() == StatusType::SUCCESS )
    {
        // Do Nothing
    }

    // Stmt 2 : If current status type is success, then replace
    //  Note: we know it is greater due to previous if.
    else if( m_status_type == StatusType::SUCCESS  )
    {
        // Replace status
        m_status_type     = new_status.m_status_type;
        m_status_reason   = new_status.m_status_reason;
        m_status_details  = new_status.m_status_details;
        m_status_appended = true;
    }


    // Stmt 3 : If current Status is not success, but new is greater, replace and append
    if( (int8_t)m_status_type < (int8_t)new_status.m_status_type )
    {
        Status tstatus;
        tstatus.m_status_type = m_status_type;
        tstatus.m_status_reason = m_status_reason;
        tstatus.m_status_details = m_status_details;

        m_status_type = new_status.m_status_type;
        m_status_reason = new_status.m_status_reason;
        m_status_details = new_status.m_status_details;

        m_status_list.push_back(tstatus);
    }

    // Stmt 4 : Neither Success, new is less than current
    else
    {
        m_status_list.push_back(new_status);
    }


}

/********************************/
/*       Append to Status       */
/********************************/
void Status::operator+=(const Status &status)
{
    Append(status);
}


/*******************************************/
/*          Print to Logger String         */
/*******************************************/
std::string Status::To_Log_String(const int &indent) const
{
    // Create gap string
    std::string gap(indent, ' ');

    // Create stringstream
    std::stringstream sin;
    sin << gap << "Type:   " << StatusTypeToString(m_status_type) << std::endl;
    sin << gap << "Reason: " << StatusReasonToString( m_status_reason) << std::endl;
    sin << gap << "Details:" << m_status_details << std::endl;

    // For each Sub-Status
    for( auto stat : m_status_list )
    {
        sin << stat.To_Log_String(indent+4) << std::endl;
    }

    return sin.str();
}


/*******************************************/
/*          Print to Pretty String         */
/*******************************************/
std::string Status::To_Pretty_String(const int &indent) const
{
    // Create gap string
    std::string gap(' ', indent);

    // Create stringstream
    std::stringstream sin;
    sin << gap << "Type:   " << StatusTypeToString(m_status_type) << std::endl;
    sin << gap << "Reason: " << StatusReasonToString( m_status_reason) << std::endl;
    sin << gap << "Details:" << m_status_details << std::endl;

    // For each Sub-Status
    for( auto stat : m_status_list )
    {
        sin << stat.To_Log_String(indent+4) << std::endl;
    }

    return sin.str();
}
