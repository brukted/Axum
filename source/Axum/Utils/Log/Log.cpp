#include "Log.h"

namespace Axum::Utils {

void Log::Startup() {
  spdlog::set_pattern("%^ [%T] %n: %v%$");

// Debug build
#ifndef NDEBUG
  Log::sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
  spdlog::set_level(spdlog::level::trace);
  Log::sink->set_level(spdlog::level::trace);
  Log::addonLogger = std::make_shared<spdlog::logger>("Addon", Log::sink);
  Log::coreLogger = std::make_shared<spdlog::logger>("Core", Log::sink);
  Log::editorLogger = std::make_shared<spdlog::logger>("Editor", Log::sink);
  Log::renderLogger = std::make_shared<spdlog::logger>("Render", Log::sink);
  Log::addonLogger->set_level(spdlog::level::trace);
  Log::coreLogger->set_level(spdlog::level::trace);
  Log::editorLogger->set_level(spdlog::level::trace);
  Log::renderLogger->set_level(spdlog::level::trace);

// Release build
#else
  std::time_t t = std::time(nullptr);
  Log::sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(
      PathUtils::userPathS +
      fmt::format("/logs/{:%Y_%m_%d-%H_%M_%S} log.txt", fmt::localtime(t)));
  spdlog::set_level(spdlog::level::info);
  Log::sink->set_level(spdlog::level::info);
  Log::addonLogger = std::make_shared<spdlog::logger>("Addon", Log::sink);
  Log::coreLogger = std::make_shared<spdlog::logger>("Core", Log::sink);
  Log::editorLogger = std::make_shared<spdlog::logger>("Editor", Log::sink);
  Log::renderLogger = std::make_shared<spdlog::logger>("Render", Log::sink);
  Log::addonLogger->set_level(spdlog::level::info);
  Log::coreLogger->set_level(spdlog::level::info);
  Log::editorLogger->set_level(spdlog::level::info);
  Log::renderLogger->set_level(spdlog::level::info);
#endif
}

void Log::Shutdown() {}

Log::~Log() { Log::getInstance().Shutdown(); }

} // namespace Axum::Utils