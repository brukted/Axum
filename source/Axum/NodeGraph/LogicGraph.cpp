/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "LogicGraph.h"

/**
 * LogicGraph implementation
 */

std::string LogicGraph::DataTypeToGLSL(DataType d)
{
    switch (d)
    {
    case DataType::int1:
        return ("int");
        break;
    case DataType::int2:
        return ("ivec2");
        break;
    case DataType::int3:
        return ("ivec3");
        break;
    case DataType::int4:
        return ("ivec4");
        break;
    case DataType::float1:
        return ("float");
        break;
    case DataType::float2:
        return ("vec2");
        break;
    case DataType::float3:
        return ("vec3");
        break;
    case DataType::float4:
        return ("vec4");
        break;
    case DataType::text:
        AX_LOG_CORE_CRITICAL("String type in glsl function graph");
        return ("void");
        break;
    default:
        AX_LOG_CORE_CRITICAL("Unkown type in glsl function graph");
        return ("void");
        break;
    }
}

std::shared_ptr<std::string> LogicGraph::compileGL()
{
    std::shared_ptr<std::string> code = std::make_shared<std::string>();
    std::vector<Node *> nodes = transverse();
    ParamCollection &c = static_cast<ParamCollection &>(mParams.GetParameter("Resource"));
    std::string &functionName = static_cast<TextParam &>(c.GetParameter("Name")).GetValue();
    DataType returnType;

    {
        if (output == nullptr)
        {
            AX_LOG_CORE_CRITICAL("Output is not assigned to the function graph")
        }
        else if (output->GetOutputSockets().size() != 0)
        {
            returnType = static_cast<LogicOutSocket &>(output->GetOutputSockets()[0]).GetType();
        }
        else if (output->GetInputSockets().size() != 0)
        {
            returnType = static_cast<LogicInSocket &>(output->GetInputSockets()[0]).GetType();
        }
        else
        {
            AX_LOG_CORE_CRITICAL("Function graph's output node has no input or output socket.")
        }
    }

    for (Node *node : nodes)
    {
        static_cast<LogicNode &>(*node).getHeaderPart(code, mParams);
    }
    code->append("\n");
    //return function name open bracket
    code->append(fmt::format("%s %s(){\n", DataTypeToGLSL(returnType), functionName));
    for (Node *node : nodes)
    {
        static_cast<LogicNode &>(*node).getFunctionPart(code, mParams);
    }
    code->append(
        "}");
    return code;
}