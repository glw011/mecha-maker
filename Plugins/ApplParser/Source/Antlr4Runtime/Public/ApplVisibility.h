#pragma once

// macros to prevent linker errors for clang/gnuc visibility but do nothing for msvc 

#if defined(__GNUC__) || defined(__clang__)
  #define APPL_VISIBILITY_PUSH  _Pragma("GCC visibility push(default)")
  #define APPL_VISIBILITY_POP   _Pragma("GCC visibility pop")
#else
  #define APPL_VISIBILITY_PUSH
  #define APPL_VISIBILITY_POP
#endif