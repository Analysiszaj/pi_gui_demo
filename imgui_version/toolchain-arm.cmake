# 设置交叉编译工具链
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_SYSROOT /home/user/arm-toolchain/sysroot)
set(CMAKE_FIND_ROOT_PATH /home/user/arm-toolchain/sysroot)
set(CMAKE_PREFIX_PATH /usr/bin/)

# 指定交叉编译工具链路径
set(tools /usr)

# 设置编译器
set(CMAKE_C_COMPILER ${tools}/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${tools}/arm-linux-gnueabihf-g++)

# 设置必要的编译器标志
set(CMAKE_C_FLAGS "-mfpu=neon -mfloat-abi=hard -march=armv7-a")
set(CMAKE_CXX_FLAGS "-mfpu=neon -mfloat-abi=hard -march=armv7-a")
