/**
 * @file    Log_Handler_Qt.hpp
 * @author  Marvin Smith
 * @date    4/17/2017
*/
#ifndef LOG_HANDLER_QT
#define LOG_HANDLER_QT

// C++ Libraries
#include <memory>

// Project Libraries
#include "Log_Handler_Base.hpp"
#include "Log_Severity.hpp"


/**
 * @class Log_Handler_Config_Qt
 */
class Log_Handler_Config_Qt : public Log_Handler_Config_Base
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Log_Handler_Config_Qt> ptr_t;

        /**
         * @brief Constructor
         */
        Log_Handler_Config_Qt( const LogSeverity& severity );


    private:

        /// Class Name
        std::string m_class_name;

};  // End of Log_Handler_Config_Qt Class


/**
 * @class Log_Handler_Qt
*/
class Log_Handler_Qt : public Log_Handler_Base
{
    public:

        /**
         * @brief Constructor
        */
        Log_Handler_Qt( Log_Handler_Config_Base::ptr_t config );




    private:

        /// Class Name
        std::string m_class_name;

        /// Configuration
        Log_Handler_Config_Qt::ptr_t m_config;

}; // End of Log_Handler_Qt Class


#endif
