/**
 * @file    TEST_CoordinateGeographic.cpp
 * @author  Marvin Smith
 * @date    9/3/2017
 */
#include <gtest/gtest.h>


// Project Libraries
#include <GeoImage/coordinate/CoordinateGeographic.hpp>


/*****************************************************/
/*          Test the Constructor Methods             */
/*****************************************************/
TEST( CoordinateGeographic, Default_Constructor )
{
    // Expected Values
    const double exp_lat_01 = 0;
    const double exp_lon_01 = 0;

    // Create test coordinate
    GEO::CoordinateGeographic test_coord;

    // Expected Values
    ASSERT_NEAR( test_coord.Get_Latitude_Degrees(),  exp_lat_01,  0.0001 );
    ASSERT_NEAR( test_coord.Get_Longitude_Degrees(), exp_lon_01, 0.0001 );
}