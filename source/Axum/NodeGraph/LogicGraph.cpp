/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "LogicGraph.h"

/**
 * LogicGraph implementation
 */

std::array<char, 52> LogicGraph::firstVariableLetters = {
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'G',
    'H',
    'I',
    'J',
    'K',
    'L',
    'M',
    'N',
    'O',
    'P',
    'Q',
    'R',
    'S',
    'T',
    'U',
    'V',
    'W',
    'X',
    'Y',
    'Z',
    'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z'};

std::array<char, 63> LogicGraph::secondaryVariableLetters = {
    ' ',
    '0',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'G',
    'H',
    'I',
    'J',
    'K',
    'L',
    'M',
    'N',
    'O',
    'P',
    'Q',
    'R',
    'S',
    'T',
    'U',
    'V',
    'W',
    'X',
    'Y',
    'Z',
    'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z'};

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
    // TODO: Find better mechanics to transfer the generator to logic nodes
    std::shared_ptr<std::string> code = std::make_shared<std::string>();
    std::vector<Node *> nodes = transverse();
    std::string &functionName = name.GetValue();
    //* 65 - 90 A - Z 97 -122 a - z 48 - 57 0 - 9
    int last1 = 0, last2 = -1;
    auto GenerateName = [&last1, &last2]() {
        //* if  the last secondary character is the last possible then proceed to the next first character
        if ((last2 + 1) >= secondaryVariableLetters.size())
        {
            ++last1;
            last2 = -1;
        }
        if (last1 >= 52)
        {
            AX_LOG_CORE_CRITICAL("Run out of variable names while compiling logic graph.")
        }
        return std::string{firstVariableLetters[last1], secondaryVariableLetters[++last2]};
    };

    DataType returnType;

    {
        if (output == nullptr)
        {
            AX_LOG_CORE_CRITICAL("Output is not assigned to the function graph")
            return nullptr;
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
            return nullptr;
        }
    }

    for (Node *node : nodes)
    {
        static_cast<LogicNode &>(*node).getHeaderPart(code, std::function{GenerateName});
    }
    code->append("\n");
    //return function name open bracket
    code->append(fmt::format("{0} {1}(){\n", DataTypeToGLSL(returnType), functionName));
    for (Node *node : nodes)
    {
        static_cast<LogicNode &>(*node).getFunctionPart(code, std::function{GenerateName});
    }
    code->append(
        "}");
    return code;
}

//TODO: add implementation
std::shared_ptr<std::string> LogicGraph::compilePy()
{
}