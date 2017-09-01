/**
 * @file    Asset_Manager.hpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#ifndef CORE_ASSETS_ASSET_MANAGER_HPP
#define CORE_ASSETS_ASSET_MANAGER_HPP

// C++ Libraries
#include <cinttypes>
#include <map>
#include <memory>
#include <string>

// Project Libraries
#include "../core/Status.hpp"
#include "../core/System_Configuration.hpp"
#include "../comm/MessageService.hpp"
#include "Asset_Base.hpp"


/**
 * @class Asset_Manager
 */
class Asset_Manager
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Asset_Manager> ptr_t;


        /**
         * @brief Initialize
         */
        static void Initialize( System_Configuration::ptr_t sys_config );


        /**
         * @brief Finalize
         */
        static void Finalize();


        /**
         * @brief Add an Asset
         */
        static int64_t Register_Asset( Asset_Base::ptr_t asset );


        /**
         * @brief Query the asset
         * @param asset_id
         * @return
         */
        static Asset_Base::ptr_t Query_Asset( const int& asset_id );


        /**
         * @brief Query asset from manager.
         * @param asset_id
         * @param status
         * @return
         */
        static Asset_Base::ptr_t Query_Asset( const int& asset_id,
                                              Status&    status );


        /**
         * @brief Register Message Service
         */
        static void Register_Message_Service( MessageService::ptr_t message_service );


    private:

        /**
         * @brief Constructor
         */
        Asset_Manager( System_Configuration::ptr_t sys_config );


        /**
         * @brief Get an instance
         */
        static Asset_Manager::ptr_t& Get_Instance();


        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// List of Registered Assets
        std::map<int64_t,Asset_Base::ptr_t> m_assets;

        /// Registered Message Service
        MessageService::ptr_t m_message_service;

};

#endif