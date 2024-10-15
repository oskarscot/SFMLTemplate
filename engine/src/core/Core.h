#pragma once

#if defined(SFT_WINDOWS)
    #ifdef SFT_BUILD_DLL
        #define SFT_API __declspec(dllexport)
    #else
        #define SFT_API __declspec(dllimport)
    #endif
#elif defined(SFT_MACOS) || defined(SFT_LINUX)
    #ifdef SFT_BUILD_DLL
        #define SFT_API __attribute__((visibility("default")))
    #else
        #define SFT_API
    #endif
#else
    #error Unsupported platform!
#endif
