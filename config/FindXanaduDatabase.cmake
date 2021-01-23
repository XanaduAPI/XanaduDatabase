# Explain
message("using FindXanaduDatabase.cmake find")

# Find XANADU_DATABASE_INCLUDE
if (WIN32)
	find_path(XANADU_DATABASE_INCLUDE XanaduDatabase/ C:/Xanadu/include/)
elseif (MINGW)
	find_path(XANADU_DATABASE_INCLUDE XanaduDatabase/ /usr/include/)
elseif (APPLE)
	find_path(XANADU_DATABASE_INCLUDE XanaduDatabase/ /usr/local/include/)
elseif (UNIX)
	find_path(XANADU_DATABASE_INCLUDE XanaduDatabase/ /usr/include/)
endif ()

# Find XANADU_DATABASE_LIBRARY
if (WIN32)
	find_path(XANADU_DATABASE_LIBRARY XanaduDatabase.lib C:/Xanadu/lib/)
elseif (MINGW)
	find_path(XANADU_DATABASE_LIBRARY XanaduDatabase.dll.a /usr/lib/)
elseif (APPLE)
	find_path(XANADU_DATABASE_LIBRARY libXanaduDatabase.dylib /usr/local/lib/)
elseif (UNIX)
	find_path(XANADU_DATABASE_LIBRARY libXanaduDatabase.so /usr/lib/)
endif ()

message("XANADU_DATABASE_INCLUDE: ${XANADU_DATABASE_INCLUDE}")
message("XANADU_DATABASE_LIBRARY: ${XANADU_DATABASE_LIBRARY}")

# Setting
if(XANADU_DATABASE_INCLUDE AND XANADU_DATABASE_LIBRARY)
	set(XANADU_DATABASE_FOUND TRUE)
endif()
