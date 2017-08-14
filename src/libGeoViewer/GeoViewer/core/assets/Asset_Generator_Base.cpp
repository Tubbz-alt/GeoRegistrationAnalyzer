/**
 * @file    Asset_Generator_Base.cpp
 * @author  Marvin Smith
 * @date    8/13/2017
 */
#include "Asset_Generator_Base.hpp"


/********************************/
/*          Constructor         */
/********************************/
Asset_Generator_Config_Base::Asset_Generator_Config_Base()
        : m_class_name("Asset_Generator_Config_Base")
{
}


/********************************/
/*          Constructor         */
/********************************/
Asset_Generator_Base::Asset_Generator_Base(Asset_Generator_Config_Base::ptr_t config)
  : m_class_name("Asset_Generator_Base"),
    m_config(config)
{

}
