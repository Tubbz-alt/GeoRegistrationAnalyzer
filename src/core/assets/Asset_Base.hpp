/**
 * @file    Asset_Base.hpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#ifndef CORE_ASSETS_ASSET_BASE_HPP
#define CORE_ASSETS_ASSET_BASE_HPP

// C++ Libraries
#include <memory>
#include <string>


/**
 * @class Asset_Base
 */
class Asset_Base
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Asset_Base> ptr_t;


        /**
         * @brief Constructor
         */
        Asset_Base();


        /**
         * @brief Print Log String
         */
        virtual std::string To_Log_String( const int& offset = 0 )const;

    private:

        /// Class Name
        std::string m_class_name;

}; // End of Asset_Base Class

#endif