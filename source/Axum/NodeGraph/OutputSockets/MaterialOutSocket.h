/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MATERIALOUTSOCKET_H
#define _MATERIALOUTSOCKET_H

#include "../OutputSocket.h"
#include "../InputSockets/MaterialInSocket.h"
#include "../Material.h"
#include <exception>
#include "Log.h"
#include <epoxy/gl.h>
#include "../Nodes/MaterialNode.h"

class MaterialOutSocket : public OutputSocket
{
private:
	/**Id of the texture on gpu used for live preview execution
	 * exists only if setup cache is called it is 0 if not initalized
	**/
	GLuint GTextureId = 0;
	Channel channel{Channel::Color};

public:
	MaterialOutSocket(std::string &_name, unsigned int _uid, Channel _channel = Channel::Color);

	MaterialOutSocket(const char *_name, unsigned int _uid, Channel _channel = Channel::Color);

	void SetupCache();

	void DeleteCache();

	GLint GetGlFormat(ImageFormat format);
	/**
	 * @brief Return id of the cached texture on the gpu 
	 *  
	 * @return GLuint ID of the texture on the GPU
	 */
	GLuint GetGPUTexture();
};

#endif //_MATERIALOUTSOCKET_H
