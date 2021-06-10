#ifndef			_XANADU_DATABASE_HEADER_H_
#define			_XANADU_DATABASE_HEADER_H_

#include <XanaduRuntime/Xanadu.h>
#include <XanaduCore/Xanadu.h>

#ifndef			_XANADU_DATABASE_BUILD_STATIC
#ifdef			_XANADU_DATABASE_BUILD_SHARED
#if defined(_XANADU_SYSTEM_WINDOWS)
#define			XANADU_DATABASE_EXPORT					__declspec(dllexport)
#else
#define			XANADU_DATABASE_EXPORT					__attribute__((visibility("default")))
#endif
#else
#if defined(_XANADU_SYSTEM_WINDOWS)
#define			XANADU_DATABASE_EXPORT					__declspec(dllimport)
#else
#define			XANADU_DATABASE_EXPORT					__attribute__((visibility("default")))
#endif
#endif
#else
#define			XANADU_DATABASE_EXPORT
#endif
#define			XANADU_DATABASE_LOCAL

#endif
