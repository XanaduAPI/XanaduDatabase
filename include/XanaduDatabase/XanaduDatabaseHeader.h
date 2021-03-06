#ifndef			_XANADU_DATABASE_HEADER_H_
#define			_XANADU_DATABASE_HEADER_H_

#include <XanaduRuntime/XanaduRuntime.h>
#include <XanaduCore/XanaduCore.h>

#ifndef			XANADU_DATABASE_BUILD_STATIC
#ifdef			XANADU_DATABASE_LIB
#ifdef XANADU_SYSTEM_WINDOWS
#define			XANADU_DATABASE_EXPORT					__declspec(dllexport)
#else
#define			XANADU_DATABASE_EXPORT					__attribute__((visibility("default")))
#endif // XANADU_SYSTEM_WINDOWS
#else
#ifdef XANADU_SYSTEM_WINDOWS
#define			XANADU_DATABASE_EXPORT					__declspec(dllimport)
#else
#define			XANADU_DATABASE_EXPORT					__attribute__((visibility("default")))
#endif // XANADU_SYSTEM_WINDOWS
#endif // XANADU_DATABASE_LIB
#else
#define			XANADU_DATABASE_EXPORT
#endif // XANADU_DATABASE_BUILD_STATIC
#define			XANADU_DATABASE_LOCAL

#endif // _XANADU_DATABASE_HEADER_H_
