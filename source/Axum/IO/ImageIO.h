/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _AXUM_IO_IMAGEIO_H_
#define _AXUM_IO_IMAGEIO_H_

#include <OpenImageIO/filesystem.h>
#include <OpenImageIO/imageio.h>
#include <assert.h>
#include <string_view>
#include <tuple>
#include <vector>

namespace Axum::IO {

OIIO::ImageSpec loadImageFromFile(std::string_view filePath,
                                  std::vector<unsigned char> &pixles);

OIIO::ImageSpec loadImageFromMemory(std::string_view fileName, void *data,
                                    size_t size,
                                    std::vector<unsigned char> &pixles);

} // namespace Axum::IO
#endif // _AXUM_IO_IMAGEIO_H_