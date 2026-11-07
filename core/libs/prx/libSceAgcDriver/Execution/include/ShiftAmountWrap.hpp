#ifndef CORE_LIBS_PRX_LIBSCEAGCDRIVER_EXECUTION_INCLUDE_SHIFTAMOUNTWRAP_HPP
#define CORE_LIBS_PRX_LIBSCEAGCDRIVER_EXECUTION_INCLUDE_SHIFTAMOUNTWRAP_HPP

#include <cstdint>
#include <cstdlib>

#include <vulkan/vulkan.h>

namespace AgcDriver {

inline bool WrapShiftAmounts(VkDriverId driver, std::uint32_t driverVersion) {
    if (const char* forced = std::getenv("APS5_SHIFT_AMOUNT_WORKAROUND"); forced != nullptr && forced[0] != '\0') return forced[0] != '0';
    return driver == VK_DRIVER_ID_MESA_HONEYKRISP && driverVersion < VK_MAKE_VERSION(26u, 3u, 0u);
}

}

#endif
