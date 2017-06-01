/**
 * @file    Log_Formatter.hpp
 * @author  Marvin Smith
 * @date    5/30/2017
 */
#ifndef LOG_LOG_FORMATTER_HPP
#define LOG_LOG_FORMATTER_HPP


// C++ Libraries
#include <memory>
#include <string>

// Project Libraries
#include "Log_Severity.hpp"
#include "../core/Config_Param.hpp"


/**
 * @class Log_Formatter
 */
class Log_Formatter
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Log_Formatter> ptr_t;

        /**
         * @brief Constructor
         */
        Log_Formatter( const Config_Param& config_params );


    private:

        /// Class Name
        std::string m_class_name;

        /// Configuration Parameters
        Config_Param m_config_params;

};


#endif