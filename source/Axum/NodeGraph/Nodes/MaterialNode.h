/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MATERIALNODE_H
#define _MATERIALNODE_H

#include "../Node.h"
#include "../OutputSockets/MaterialOutSocket.h"
#include "../InputSockets/MaterialInSocket.h"
#include "../Material.h"
#include "../../Parameter/EnumParam.h"
#include "../../Parameter/Float2Param.h"
#include "../../Parameter/IntegerParam.h"
#include "../../Parameter/Integer2Param.h"
#include "boost/serialization/base_object.hpp"

static const std::map<int, std::string> outputSizes{
    {8, "8"},
    {16, "16"},
    {32, "32"},
    {64, "64"},
    {128, "128"},
    {256, "256"},
    {512, "512"},
    {1024, "1024"},
    {2048, "2048"},
    {4096, "4096"}};

static const std::map<int, std::string> imageFormats{
    {ImageFormat::EIGHT_BIT, "8 bit"},
    {ImageFormat::SIXTEEN_BIT, "16 bit"},
    {ImageFormat::SIXTEEN_BIT_FLOAT, "16 bit float"},
    {ImageFormat::THIRTY_TWO_BIT_FLOAT, "32 bit float"}};

class MaterialNode : public Node
{
    friend class boost::serialization::access;

public:
    ParamCollection common{mNodeParams.GenerateUid(), "Common"};
    ParamCollection size{common.GenerateUid(), "Size"};
    EnumParam width{size.GenerateUid(), "Width", outputSizes, 1024};
    EnumParam height{size.GenerateUid(), "Height", outputSizes, 1024};
    EnumParam imageFormat{common.GenerateUid(), "Image format", imageFormats, ImageFormat::EIGHT_BIT};
    IntegerParam seed{common.GenerateUid(), "Random seed", 0};

    /**
     * @brief Don't use it.Construct a new Material Node object.
     * 
     */
    MaterialNode();

    MaterialNode(unsigned int _uid);

    /**
     * @brief Initializes textures on the GPU.
     * 
     */
    void SetupCache();

    /**
     * @brief Deletes textures on the GPU.
     * 
     */
    void DeleteCache();

    /**
     * @brief Executes compiles the shader process and writes data on textures in each output sockets.
     * 
     */
    virtual void Excute();

    /**
     * @brief Excutes the node and nodes that are connected to it's output sockets.
     * 
     */
    void ExcuteForward();

private:
    template <class Archive>
    void save(Archive &ar, const unsigned int version) const
    {
        ar &width, &height, &imageFormat, &seed;
        ar &size, &common;
    }

    template <class Archive>
    void load(Archive &ar, const unsigned int version)
    {
        ar &width, &height, &imageFormat, &seed;
        ar &size, &common;
    }
    BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(MaterialNode, 1)
#endif //_MATERIALNODE_H
