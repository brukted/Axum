/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MATERIALGRAPH_H
#define _MATERIALGRAPH_H

#include "Graph.h"
#include "Nodes/MaterialNode.h"
#include "Material.h"
#include "../../Parameter/EnumParam.h"
#include "../../Parameter/Float2Param.h"
#include "../../Parameter/IntegerParam.h"
#include "../../Parameter/Integer2Param.h"

class MaterialGraph : public Graph
{
    friend class boost::serialization::access;

public:
    ParamCollection defaultParams{mParams.GenerateUid(), "Default Parameters"};
    ParamCollection size{defaultParams.GenerateUid(), "Size"};
    EnumParam width{size.GenerateUid(), "Width", outputSizes, 1024};
    EnumParam height{size.GenerateUid(), "Height", outputSizes, 1024};
    EnumParam imageFormat{defaultParams.GenerateUid(), "Image format", imageFormats, ImageFormat::EIGHT_BIT};
    IntegerParam seed{defaultParams.GenerateUid(), "Random seed", 0};
    ParamCollection exposedParams{mParams.GenerateUid(), "Exposed Parameters"};

    MaterialGraph(unsigned int _uid);

    void SetupCache();

    void DeleteCache();

    void Process();

private:
    template <class Archive>
    void save(Archive &ar, const unsigned int version) const
    {
        ar &boost::serialization::base_object<Graph>(*this);
        ar &size, &width, &height, &imageFormat, &seed;
        ar &defaultParams, &size, &exposedParams;
    }

    template <class Archive>
    void load(Archive &ar, const unsigned int version)
    {
        ar &boost::serialization::base_object<Graph>(*this);
        ar &size, &width, &height, &imageFormat, &seed;
        ar &defaultParams, &size, &exposedParams;
    }
    BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(MaterialGraph, 1)
#endif //_MATERIALGRAPH_H
