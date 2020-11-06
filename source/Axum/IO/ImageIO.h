/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _AXUM_IO_IMAGEIO_H_
#define _AXUM_IO_IMAGEIO_H_

#include <string_view>
#include <tuple>
#include <vector>

namespace Axum::IO {

/**
 * @brief Loads the image at @a filePath to @a pixles as RGBA 8bit.
 *
 * @param filePath path to the image
 * @param pixles vector to put the pixles
 * @return std::tuple<int, int> {width,height}
 * @throw std::runtime_error if it can't load the image
 */
std::tuple<int, int> loadImageFromFile(std::string_view filePath,
                                       std::vector<unsigned char> &pixles);

/**
 * @brief Loads the image from memory @a data to @a pixles as RGBA 8bit.
 *
 * @param fileName name of the file before it was loaded to memory.
 * @param data pointer to the data at memory.
 * @param size size of the data.
 * @param pixles vector to put the pixles.
 * @return std::tuple<int, int> {width,height}
 * @throw std::runtime_error if it can't load the image
 */
std::tuple<int, int> loadImageFromMemory(std::string_view fileName, void *data,
                                         size_t size,
                                         std::vector<unsigned char> &pixles);

} // namespace Axum::IO
#endif // _AXUM_IO_IMAGEIO_H_