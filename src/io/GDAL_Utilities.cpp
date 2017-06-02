/**
 * @file    GDAL_Utilities.hpp
 * @author  Marvin Smith
 * @date    6/2/2017
 */


/*********************************************************/
/*           Convert GDAL Data Type To Bytes             */
/*********************************************************/
size_t GDAL_Data_Type_To_Bytes( const GDALDataType& gdal_type )
{
    switch(gdal_type)
    {
        case GDALDataType::GDT_Byte:
            return 1;
        case GDALDataType::GDT_Int16:
            return 2;
        case GDALDataType::GDT_UInt16:
            return 2;
        case GDALDataType::GDT_Int32:
            return 4;
        case GDALDataType::GDT_UInt32:
            return 4;
    }
    return 0;
}