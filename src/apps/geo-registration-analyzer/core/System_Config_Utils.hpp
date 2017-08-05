/**
 * @brief System_Config_Utils.hpp
 * @author  Marvin Smith
 * @date    5/12/2017
 */
#ifndef CORE_SYSTEM_CONFIG_UTILS_HPP
#define CORE_SYSTEM_CONFIG_UTILS_HPP

// Project Libraries
#include <GeoViewer/core/System_Configuration.hpp>

// C++ Libraries
#include <map>
#include <string>

/**
 * @class Viewer_Config_Generator
 */
class Viewer_Config_Generator : public Default_Config_Generator
{
    public:

        /**
         * @brief Generate Configuration Options.
         * @return
         */
        Config_Param Generate();
};

#endif