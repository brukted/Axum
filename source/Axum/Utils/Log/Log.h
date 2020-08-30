/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef LOG_H
#define LOG_H

#define FMT_HEADER_ONLY

#include "PathUtils.h"
#include <chrono>
#include <fmt/chrono.h>
#include <fmt/format.h>
#include <spdlog/logger.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace Axum {
namespace Utils {
class Log {
private:
  spdlog::sink_ptr sink;

public:
  std::shared_ptr<spdlog::logger> coreLogger;
  std::shared_ptr<spdlog::logger> addonLogger;
  std::shared_ptr<spdlog::logger> editorLogger;
  std::shared_ptr<spdlog::logger> renderLogger;

public:
  static Log &getInstance() {
    static Log instance;
    return instance;
  }

private:
  Log(){};
  ~Log();

public:
  Log(Log const &) = delete;
  void operator=(Log const &) = delete;

  void Startup();

  void Shutdown();
};
} // namespace Utils
} // namespace Axum

#define AX_LOG_ADDON_TRACE(...)                                                \
  Axum::Utils::Log::getInstance().addonLogger->trace(__VA_ARGS__);
#define AX_LOG_ADDON_WARN(...)                                                 \
  Axum::Utils::Log::getInstance().addonLogger->warn(__VA_ARGS__);
#define AX_LOG_ADDON_INFO(...)                                                 \
  Axum::Utils::Log::getInstance().addonLogger->info(__VA_ARGS__);
#define AX_LOG_ADDON_DEBUG(...)                                                \
  Axum::Utils::Log::getInstance().addonLogger->debug(__VA_ARGS__);
#define AX_LOG_ADDON_ERROR(...)                                                \
  Axum::Utils::Log::getInstance().addonLogger->error(__VA_ARGS__);
#define AX_LOG_ADDON_CRITICAL(...)                                             \
  Axum::Utils::Log::getInstance().addonLogger->critical(__VA_ARGS__);

#define AX_LOG_CORE_TRACE(...)                                                 \
  Axum::Utils::Log::getInstance().coreLogger->trace(__VA_ARGS__);
#define AX_LOG_CORE_WARN(...)                                                  \
  Axum::Utils::Log::getInstance().coreLogger->warn(__VA_ARGS__);
#define AX_LOG_CORE_INFO(...)                                                  \
  Axum::Utils::Log::getInstance().coreLogger->info(__VA_ARGS__);
#define AX_LOG_CORE_DEBUG(...)                                                 \
  Axum::Utils::Log::getInstance().coreLogger->debug(__VA_ARGS__);
#define AX_LOG_CORE_ERROR(...)                                                 \
  Axum::Utils::Log::getInstance().coreLogger->error(__VA_ARGS__);
#define AX_LOG_CORE_CRITICAL(...)                                              \
  Axum::Utils::Log::getInstance().coreLogger->critical(__VA_ARGS__);

#define AX_LOG_EDITOR_TRACE(...)                                               \
  Axum::Utils::Log::getInstance().editorLogger->trace(__VA_ARGS__);
#define AX_LOG_EDITOR_WARN(...)                                                \
  Axum::Utils::Log::getInstance().editorLogger->warn(__VA_ARGS__);
#define AX_LOG_EDITOR_INFO(...)                                                \
  Axum::Utils::Log::getInstance().editorLogger->info(__VA_ARGS__);
#define AX_LOG_EDITOR_DEBUG(...)                                               \
  Axum::Utils::Log::getInstance().editorLogger->debug(__VA_ARGS__);
#define AX_LOG_EDITOR_ERROR(...)                                               \
  Axum::Utils::Log::getInstance().editorLogger->error(__VA_ARGS__);
#define AX_LOG_EDITOR_CRITICAL(...)                                            \
  Axum::Utils::Log::getInstance().editorLogger->critical(__VA_ARGS__);

#define AX_LOG_RENDER_TRACE(...)                                               \
  Axum::Utils::Log::getInstance().renderLogger->trace(__VA_ARGS__);
#define AX_LOG_RENDER_WARN(...)                                                \
  Axum::Utils::Log::getInstance().renderLogger->warn(__VA_ARGS__);
#define AX_LOG_RENDER_INFO(...)                                                \
  Axum::Utils::Log::getInstance().renderLogger->info(__VA_ARGS__);
#define AX_LOG_RENDER_DEBUG(...)                                               \
  Axum::Utils::Log::getInstance().renderLogger->debug(__VA_ARGS__);
#define AX_LOG_RENDER_ERROR(...)                                               \
  Axum::Utils::Log::getInstance().renderLogger->error(__VA_ARGS__);
#define AX_LOG_RENDER_CRITICAL(...)                                            \
  Axum::Utils::Log::getInstance().renderLogger->critical(__VA_ARGS__);

#endif