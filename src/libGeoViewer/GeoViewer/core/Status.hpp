/**
 * @file    Status.hpp
 * @author  Marvin Smith
 * @date    6/3/2017
 */
#ifndef LIB_GEO_VIEWER_CORE_STATUS_HPP
#define LIB_GEO_VIEWER_CORE_STATUS_HPP

// C++ Libraries
#include <cinttypes>
#include <string>


/**
 * @enum StatusType
 */
enum class StatusType : int8_t
{
        UNKNOWN = 0 /**< This should be an error condition.*/,
        SUCCESS = 1 /**< No errors or failures*/,
        WARNING = 2 /**< Minor issues*/,
        FAILURE = 3 /**< Fail state.*/,
};


/**
 * @brief Convert a StatusType to String
 * @param status_type
 * @return
 */
std::string StatusTypeToString( const StatusType& status_type );


/**
 * @brief Convert String to a StatusType
 * @param status_type
 * @return
 */
StatusType StringToStatusType( const std::string& status_type );


/**
 * @class Status
 */
class Status
{
    public:

        /**
         * @brief Default Constructor
         */
        Status();


        /**
         * @brief Parameterized Constructor
         */

    private:

        /// Class Name
        std::string m_class_name;

        /// Status Type
        StatusType m_status_type;

        /// Status Reason
        int16_t m_status_reason;

        /// Description
        std::string m_status_details;
};


#endif