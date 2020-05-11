#include "Log.h"

void Log::Startup()
{
    spdlog::set_pattern("%^ [%T] %n: %v%$");
//Debug build
#ifndef NDEBUG
    Log::sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    Log::sink->set_level(spdlog::level::trace);
//Release build
#else
    ALog::sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/log.txt");
    spdlog::set_level(spdlog::level::info);
#endif
    Log::addonLogger = std::make_shared<spdlog::logger>("Addon", Log::sink);
    Log::editorLogger = std::make_shared<spdlog::logger>("Editor", Log::sink);
    Log::renderLogger = std::make_shared<spdlog::logger>("Render", Log::sink);
}

void Log::Shutdown()
{
}

Log::~Log()
{
    Log::getInstance().Shutdown();
}