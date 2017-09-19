/**
 * @file    Status.hpp
 * @author  Marvin Smith
 * @date    6/3/2017
 */
#ifndef LIB_GEO_IMAGE_CORE_STATUS_HPP
#define LIB_GEO_IMAGE_CORE_STATUS_HPP

// C++ Libraries
#include <cinttypes>
#include <deque>
#include <string>
#include <vector>


// Project Libraries
#include "StatusReason.hpp"

namespace GEO {

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
std::string StatusTypeToString(const StatusType &status_type);


/**
 * @brief Convert String to a StatusType
 * @param status_type
 * @return
 */
StatusType StringToStatusType(const std::string &status_type);


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
        Status(const StatusType &status_type,
               const StatusReason &status_reason,
               const std::string &status_details)
            : m_class_name("Status"),
              m_status_type(status_type),
              m_status_reason(status_reason),
              m_status_details(status_details)
        {
        }


        /**
         * @brief
         */
        inline StatusType Get_Status_Type() const {
            return m_status_type;
        }


        inline StatusReason Get_Status_Reason() const {
            return m_status_reason;
        }


        /**
         * @brief Get the status detail string.
         *
         * @return
         */
        inline std::string Get_Status_Details() const {
            return m_status_details;
        }


        /**
         * @brief Append Status
         */
        void Append(const Status &new_status);


        /**
         * @brief Append Status Components
         */
        void Append(const StatusType &status_type,
                    const StatusReason &status_reason,
                    const std::string &status_details);


        /**
         * @brief Append Operator
         */
        void operator+=(const Status &status);


        /**
         * @brief Check if not a failure
         */
        inline bool Not_Failure() const {
            return (m_status_type == StatusType::SUCCESS ||
                    m_status_type == StatusType::WARNING);
        }


        /**
         * @brief Check if not a success
         */
        inline bool Not_Success() const {
            return (m_status_type != StatusType::SUCCESS);
        }


        /**
         * @brief Check if a success
         */
        inline bool Is_Success() const {
            return (m_status_type == StatusType::SUCCESS);
        }


        /**
         * @brief Print to Log String
         */
        std::string To_Log_String(const int &indent = 0) const;


        /**
         * @brief To Pretty String
         */
        std::string To_Pretty_String(const int &indent = 0) const;


        /**
         * @brief Return Successful Type
         * @return
         */
        inline static Status SUCCESS()
        {
                return Status(StatusType::SUCCESS,
                              StatusReason::NO_ERRORS,
                              "");
        }

    private:

        /// Class Name
        std::string m_class_name;

        /// Status Type
        StatusType m_status_type;

        /// Status Reason
        StatusReason m_status_reason;

        /// Description
        std::string m_status_details;

        /// Internal Status List
        std::vector<Status> m_status_list;

        /// Flag if status set
        bool m_status_appended;
};

} // End of GEO Namespace

#endif