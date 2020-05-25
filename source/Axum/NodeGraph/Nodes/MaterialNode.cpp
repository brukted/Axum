/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "MaterialNode.h"

/**
 * MaterialNode implementation
 * 
 * A base class for all material nodes such as texture,normal etc.
 */

MaterialNode::MaterialNode()
{
}

MaterialNode::MaterialNode(unsigned int _uid) : Node(_uid)
{
    size.AddParameter(&width);
    size.AddParameter(&height);
    common.AddParameter(&size);
    common.AddParameter(&imageFormat);
    common.AddParameter(&seed);
    mNodeParams.AddParameter(&common);
}

void MaterialNode::SetupCache()
{
    for (auto &socket : mOutputSockets)
    {
        static_cast<MaterialOutSocket &>(socket).SetupCache();
    }
}

void MaterialNode::DeleteCache()
{
    for (auto &socket : mOutputSockets)
    {
        static_cast<MaterialOutSocket &>(socket).DeleteCache();
    }
}

void MaterialNode::Excute() { return; }

void MaterialNode::ExcuteForward()
{
    for (auto var : mInputSockets)
    {
        if (var.LinkedSocket->ParentNode->GetNeedUpdate() == true)
        {
            return; //* Do nothing inputs are not satisfied yet
        }
    }

    Excute();
    for (auto &socket : mOutputSockets)
    {
        for (auto inSocket : socket.LinkedSockets)
        {
            static_cast<MaterialNode &>(*(inSocket->ParentNode)).ExcuteForward();
        }
    }
}
