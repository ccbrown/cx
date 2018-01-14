#pragma once

#include <cx.hpp>

namespace cx::sys::unix {

enum : Int {
	AT_FDCWD            = -0x2,
	AT_REMOVEDIR        = 0x80,
	AT_SYMLINK_FOLLOW   = 0x40,
	AT_SYMLINK_NOFOLLOW = 0x20,
};

} // namespace cx::sys::unix