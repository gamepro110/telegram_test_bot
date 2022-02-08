# app config
file(
    GLOB_RECURSE
    app_src
    "src/*.cpp"
    "src/*.h"
)

find_package(
    Threads
    REQUIRED
)


add_executable(
    botApp
    ${app_src}
)

target_link_libraries(
    botApp
    PUBLIC
    TgBot
)

target_include_directories(
    botApp
    PUBLIC
    "${vendorPath}/tgbot-cpp/include/"
)