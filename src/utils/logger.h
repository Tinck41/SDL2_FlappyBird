#pragma once

#include "spdlog/spdlog.h"

namespace FB::utils {
	template <typename... Args>
	void LOG_INFO(const std::string& message, Args&&... args) {
		spdlog::info(message, std::forward<Args>(args)...);
	}
	
	template <typename... Args>
	void LOG_DEBUG(const std::string& message, Args&&... args) {
		spdlog::debug(message, std::forward<Args>(args)...);
	}
	
	template <typename... Args>
	void LOG_WARN(const std::string& message, Args&&... args) {
		spdlog::warn(message, std::forward<Args>(args)...);
	}
	
	template <typename... Args>
	void LOG_ERROR(const std::string& message, Args&&... args) {
		spdlog::error(message, std::forward<Args>(args)...);
	}
	
}
