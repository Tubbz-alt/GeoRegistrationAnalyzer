/**
 * @file    String_Utilities.hpp
 * @author  Marvin Smith
 * @date    5/12/2017
 */
#ifndef LIB_GEO_UTILITY_STRING_UTILITIES_HPP
#define LIB_GEO_UTILITY_STRING_UTILITIES_HPP

// C++ Standard Libraries
#include <cinttypes>
#include <sstream>
#include <string>
#include <vector>

/**
 * @enum StringDirection
 */
enum class StringDirection : uint8_t
{
    LEFT  = 1,
    RIGHT = 2,
    BOTH  = 3,
}; // End of StringDirection Enum Class


/**
 * @brief Trim a string.
 *
 * @param[in] data Data to trim.
 * @param[in] strip_patterns Pattern to strip.
 * @param[in] strip_direction Direction to strip.
 *
 * @return Resulting string.
 */
std::string String_Trim( const std::string&     data,
                         const std::string&     strip_patterns,
                         const StringDirection& strip_direction);

/**
 * @brief Trim a string.
 *
 * @param[in] data Data to trim.
 * @param[in] strip_direction Direction to strip.
 *
 * @return Trimmed string.
 */
std::string String_Trim( const std::string&     data,
                         const StringDirection& strip_direction);


/**
 * @brief Trim a string.
 *
 * @param[in] data Data to trim.
 * @param[in] strip_pattern Pattern to strip.
 *
 * @return Trimmed string.
 */
std::string String_Trim( const std::string&     data,
                         const std::string&     strip_pattern );


/**
 * @brief Trim a string.
 *
 * @param[in] data Data to trim.
 *
 * @return Resulting string.
 */
std::string String_Trim( const std::string&     data );


/**
 * @brief Split the string into multiple elements.
 *
 * @param[in] data Data to split.
 * @param[in] pattern Pattern to split with.
 *
 * @return List of strings.
 */
std::vector<std::string> String_Split( const std::string& data,
                                       const std::string& pattern = " ");

#endif