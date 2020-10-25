#include "Log.h"
#include <glbinding/gl43core/gl.h>
#include <glbinding/glbinding.h>

namespace Axum::Utils {
void Log::logGLErrors(const char *file, int line) {
  gl::GLenum errorCode;
  while ((errorCode = gl::glGetError()) != gl::GL_NO_ERROR) {
    std::string error;
    switch (errorCode) {
    case gl::GL_INVALID_ENUM:
      glLogger->error("INVALID_ENUM | {}({})", file, line);
      break;
    case gl::GL_INVALID_VALUE:
      glLogger->error("INVALID_VALUE | {}({})", file, line);
      break;
    case gl::GL_INVALID_OPERATION:
      glLogger->error("INVALID_OPERATION | {}({})", file, line);
      error = "INVALID_OPERATION";
      break;
    case gl::GL_STACK_OVERFLOW:
      glLogger->error("STACK_OVERFLOW | {}({})", file, line);
      break;
    case gl::GL_STACK_UNDERFLOW:
      glLogger->error("STACK_UNDERFLOW | {}({})", file, line);
      break;
    case gl::GL_OUT_OF_MEMORY:
      glLogger->error("OUT_OF_MEMORY | {}({})", file, line);
      break;
    case gl::GL_INVALID_FRAMEBUFFER_OPERATION:
      glLogger->error("INVALID_FRAMEBUFFER_OPERATION | {}({})", file, line);
      break;
    }
  }
}

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
  Log::glLogger = std::make_shared<spdlog::logger>("OpenGL", Log::sink);
  Log::glLogger->set_level(spdlog::level::trace);
  Log::addonLogger->set_level(spdlog::level::trace);
  Log::coreLogger->set_level(spdlog::level::trace);
  Log::editorLogger->set_level(spdlog::level::trace);
  Log::renderLogger->set_level(spdlog::level::trace);

// Release build
#else
  std::time_t t = std::time(nullptr);
  Log::sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(
      PathUtils::LogDirectory +
      fmt::format("/{:%Y_%m_%d-%H_%M_%S} log.txt", fmt::localtime(t)));
  spdlog::set_level(spdlog::level::info);
  Log::sink->set_level(spdlog::level::info);
  Log::addonLogger = std::make_shared<spdlog::logger>("Addon", Log::sink);
  Log::coreLogger = std::make_shared<spdlog::logger>("Core", Log::sink);
  Log::editorLogger = std::make_shared<spdlog::logger>("Editor", Log::sink);
  Log::renderLogger = std::make_shared<spdlog::logger>("Render", Log::sink);
  Log::glLogger = std::make_shared<spdlog::logger>("OpenGL", Log::sink);
  Log::glLogger->set_level(spdlog::level::trace);
  Log::addonLogger->set_level(spdlog::level::info);
  Log::coreLogger->set_level(spdlog::level::info);
  Log::editorLogger->set_level(spdlog::level::info);
  Log::renderLogger->set_level(spdlog::level::info);
#endif
}

void Log::Shutdown() {}

Log::~Log() { Log::getInstance().Shutdown(); }

} // namespace Axum::Utils