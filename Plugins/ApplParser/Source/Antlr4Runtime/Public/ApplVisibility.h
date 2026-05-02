#pragma once

// macros to prevent linker errors

#if defined(__GNUC__) || defined(__clang__)
  #define APPL_API  __attribute__((visibility("default")))
  #define APPL_VISIBILITY_PUSH  _Pragma("GCC visibility push(default)")
  #define APPL_VISIBILITY_POP   _Pragma("GCC visibility pop")
#elif defined(_MSC_VER)
  #ifdef  APPL_LANG_EXPORTS
    #define APPL_API __declspec(dllexport)
  #else
    #define APPL_API __declspec(dllimport)
  #endif
  #define APPL_VISIBILITY_PUSH
  #define APPL_VISIBILITY_POP
#else
  #define APPL_API
  #define APPL_VISIBILITY_PUSH
  #define APPL_VISIBILITY_POP
#endif