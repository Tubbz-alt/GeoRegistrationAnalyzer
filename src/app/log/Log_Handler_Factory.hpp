/**
 * @file    Log_Handler_Factory.hpp
 * @author  Marvin Smith
 * @date    4/20/2017
*/
#ifndef LOG_HANDLER_FACTORY
#define LOG_HANDLER_FACTORY

// Project Libraries
#include "Log_Handler_Base.hpp"

class Log_Handler_Factory
{
    public:

        /**
         * @brief Create Log Handler
        */
        static Log_Handler_Base::ptr_t  Create( Log_Handler_Config_Base::ptr_t config );


}; // End of Log_Handler_Factory Class


#endif
