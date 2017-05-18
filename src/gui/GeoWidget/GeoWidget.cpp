/**
 * @class GeoWidget.cpp
 * @author  Marvin Smith
 * @date    5/12/2017
 */
#include "GeoWidget.hpp"

// Qt Libraries
#include <QVBoxLayout>


/*********************************/
/*          Constructor          */
/*********************************/
GeoWidget::GeoWidget( const std::string&          base_config_profile,
                      System_Configuration::ptr_t sys_config,
                      QWidget*                    parent)
 : QWidget(parent),
   m_sys_config(sys_config),
   m_class_name("GeoWidget"),
   m_base_config_profile(base_config_profile)
{
    // Initialize Config
    Update_Configuration();

    // Initialize GUI
    Initialize_GUI();
}


/****************************************/
/*          Update Configuration        */
/****************************************/
void GeoWidget::Update_Configuration()
{

}


/***********************************/
/*          Initialize GUI         */
/***********************************/
void GeoWidget::Initialize_GUI()
{
    bool value_found;
    std::string provider = m_sys_config->Query_Config_Param(m_base_config_profile + ".provider",
                                                            value_found);
    std::cout << "Base Profile: " << m_base_config_profile << ", Loading Provider: " << provider << std::endl;

    // Create the layout
    QVBoxLayout* main_layout = new QVBoxLayout();

    // Create the viewers
    m_geo_viewers[provider] = GeoViewerFactory::Create( m_base_config_profile, m_sys_config, provider);
    main_layout->addWidget(m_geo_viewers[provider]);


    // set main layout
    setLayout(main_layout);
}
