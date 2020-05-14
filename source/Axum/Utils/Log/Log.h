#define FMT_HEADER_ONLY

#include "spdlog/spdlog.h"
#include "spdlog/logger.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#ifndef LOG_H
#define LOG_H

class Log
{
private:
	spdlog::sink_ptr sink;

public:
	std::shared_ptr<spdlog::logger> coreLogger;
	std::shared_ptr<spdlog::logger> addonLogger;
	std::shared_ptr<spdlog::logger> editorLogger;
	std::shared_ptr<spdlog::logger> renderLogger;

public:
	static Log &getInstance()
	{
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

#define AX_LOG_ADDON_TRACE(...) Log::getInstance().addonLogger->trace(__VA_ARGS__);
#define AX_LOG_ADDON_WARN(...) Log::getInstance().addonLogger->warn(__VA_ARGS__);
#define AX_LOG_ADDON_INFO(...) Log::getInstance().addonLogger->info(__VA_ARGS__);
#define AX_LOG_ADDON_DEBUG(...) Log::getInstance().addonLogger->debug(__VA_ARGS__);
#define AX_LOG_ADDON_ERROR(...) Log::getInstance().addonLogger->error(__VA_ARGS__);
#define AX_LOG_ADDON_CRITICAL(...) Log::getInstance().addonLogger->critical(__VA_ARGS__);

#define AX_LOG_CORE_TRACE(...) Log::getInstance().coreLogger->trace(__VA_ARGS__);
#define AX_LOG_CORE_WARN(...) Log::getInstance().coreLogger->warn(__VA_ARGS__);
#define AX_LOG_CORE_INFO(...) Log::getInstance().coreLogger->info(__VA_ARGS__);
#define AX_LOG_CORE_DEBUG(...) Log::getInstance().coreLogger->debug(__VA_ARGS__);
#define AX_LOG_CORE_ERROR(...) Log::getInstance().coreLogger->error(__VA_ARGS__);
#define AX_LOG_CORE_CRITICAL(...) Log::getInstance().coreLogger->critical(__VA_ARGS__);

#define AX_LOG_EDITOR_TRACE(...) Log::getInstance().editorLogger->trace(__VA_ARGS__);
#define AX_LOG_EDITOR_WARN(...) Log::getInstance().editorLogger->warn(__VA_ARGS__);
#define AX_LOG_EDITOR_INFO(...) Log::getInstance().editorLogger->info(__VA_ARGS__);
#define AX_LOG_EDITOR_DEBUG(...) Log::getInstance().editorLogger->debug(__VA_ARGS__);
#define AX_LOG_EDITOR_ERROR(...) Log::getInstance().editorLogger->error(__VA_ARGS__);
#define AX_LOG_EDITOR_CRITICAL(...) Log::getInstance().editorLogger->critical(__VA_ARGS__);

#define AX_LOG_RENDER_TRACE(...) Log::getInstance().renderLogger->trace(__VA_ARGS__);
#define AX_LOG_RENDER_WARN(...) Log::getInstance().renderLogger->warn(__VA_ARGS__);
#define AX_LOG_RENDER_INFO(...) Log::getInstance().renderLogger->info(__VA_ARGS__);
#define AX_LOG_RENDER_DEBUG(...) Log::getInstance().renderLogger->debug(__VA_ARGS__);
#define AX_LOG_RENDER_ERROR(...) Log::getInstance().renderLogger->error(__VA_ARGS__);
#define AX_LOG_RENDER_CRITICAL(...) Log::getInstance().renderLogger->critical(__VA_ARGS__);

#endif