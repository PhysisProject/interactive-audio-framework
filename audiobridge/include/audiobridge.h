/// @file audiobridge.h
/// @brief bridge between Cpp code and a dll for unity
/// Dispositif d'Intégration de Vocalisation dans les ressources d' Apprentissages
/// @author Damien Henry
/// @copyright AudioGaming 2013

#ifndef AG_AUDIO_BRIDGE_H_
#define AG_AUDIO_BRIDGE_H_

#include <string>  // needed for gcc
#include <vector>  // we store file to process in a vector

// This product "diva" is a dll :
#define _AGPRODUCTS_DLL_EXPORTS 1

// OS detection
#ifndef __AGPRODUCTS_OS
#define __AGPRODUCTS_OS
#if defined(_WIN32)
#  define __AGPRODUCTS_OS_WIN32 1
#elif defined(__linux__)
#  define __AGPRODUCTS_OS_LINUX 1
#elif defined (__APPLE__)  //to be sure it is the right test for mac os X
#  define __AGPRODUCTS_OS_OSX 1
#elif defined (SN_TARGET_PS3)
#  define __AGPRODUCTS_OS_PS3 1
#elif defined (SN_TARGET_PS3_SPU)
#  define __AGPRODUCTS_OS_PS3_SPU 1
#else
#  error "Undetected operating system"
#endif
#endif // __AGPRODUCTS_OS

#define AG_AUDIOBRIDGE_DLL_EXPORT
#if defined(__AGPRODUCTS_OS_WIN32)
# if (_AGPRODUCTS_NO_EXPORTS)
#  undef AG_AUDIOBRIDGE_DLL_EXPORT
#  define AG_AUDIOBRIDGE_DLL_EXPORT
# else  
#  if (_AGPRODUCTS_DLL_EXPORTS)
#   undef AG_AUDIOBRIDGE_DLL_EXPORT
#   define AG_AUDIOBRIDGE_DLL_EXPORT __declspec(dllexport)
#  else
#   undef AG_AUDIOBRIDGE_DLL_EXPORT
#   define AG_AUDIOBRIDGE_DLL_EXPORT __declspec(dllimport)
#  endif  
# endif
#endif

extern "C" {
  AG_AUDIOBRIDGE_DLL_EXPORT void init();
  AG_AUDIOBRIDGE_DLL_EXPORT void set_parameter(float value);
  AG_AUDIOBRIDGE_DLL_EXPORT void process(int block_size);
  AG_AUDIOBRIDGE_DLL_EXPORT int get_value(int sample_count);
}
#endif AG_AUDIO_BRIDGE_H_