/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include <map>
#include <string>

enum ImageFormat
{
    EIGHT_BIT,
    SIXTEEN_BIT,
    SIXTEEN_BIT_FLOAT,
    THIRTY_TWO_BIT_FLOAT
};

static const std::map<int, std::string> outputSizes{
    {8, "8"},     {16, "16"},   {32, "32"},     {64, "64"},     {128, "128"},
    {256, "256"}, {512, "512"}, {1024, "1024"}, {2048, "2048"}, {4096, "4096"}};

static const std::map<int, std::string> imageFormats{
    {ImageFormat::EIGHT_BIT, "8 bit"},
    {ImageFormat::SIXTEEN_BIT, "16 bit"},
    {ImageFormat::SIXTEEN_BIT_FLOAT, "16 bit float"},
    {ImageFormat::THIRTY_TWO_BIT_FLOAT, "32 bit float"}};
#endif