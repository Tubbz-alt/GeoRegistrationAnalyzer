/**
 * @file    Log_Handler_Base.hpp
 * @author  Marvin Smith
 * @date    4/17/2017
*/
#ifndef LOG_HANDLER_BASE
#define LOG_HANDLER_BASE

// C++ Libraries
#include <memory>


/**
 * @brief Log Handler Configuration
*/
class Log_Handler_Config_Base
{
    public:

        // Pointer Type
        typedef std::shared_ptr<Log_Handler_Config_Base> ptr_t;

        /**
         * @brief Log Handler
        */
        Log_Handler_Config_Base();


    private:

        /// Class Name
        std::string m_class_name;

}; // End of Log Handler Config Base Class

/**
 * @class Log_Handler_Base
*/
class Log_Handler_Base
{
    public:

        /**
         * @brief Constructor
        */
        Log_Handler_Base( Log_Handler_Config_Base::ptr_t config );


    private:

        /// Class Name
        std::string m_class_name;

        /// Configuration
        Log_Handler_Config_Base::ptr_t m_config;

}; // End of Log_Handler_Base Class

#endif
