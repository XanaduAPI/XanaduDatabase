# 辅助输出信息
message("using FindXanaduDatabase.cmake find")

# 将头文件路径赋值给 XANADU_DATABASE_INCLUDE
if (WIN32)
	FIND_PATH(XANADU_DATABASE_INCLUDE XanaduDatabase/ C:/Xanadu/include/)
elseif (MINGW)
	FIND_PATH(XANADU_DATABASE_INCLUDE XanaduDatabase/ /usr/include/)
elseif (APPLE)
	FIND_PATH(XANADU_DATABASE_INCLUDE XanaduDatabase/ /usr/local/include/)
elseif (UNIX)
	FIND_PATH(XANADU_DATABASE_INCLUDE XanaduDatabase/ /usr/include/)
endif ()

# 将库文件路径赋值给 XANADU_DATABASE_LIBRARY
if (WIN32)
	FIND_PATH(XANADU_DATABASE_LIBRARY XanaduDatabase.lib C:/Xanadu/lib/)
elseif (MINGW)
	FIND_PATH(XANADU_DATABASE_LIBRARY XanaduDatabase.dll.a /usr/lib/)
elseif (APPLE)
	FIND_PATH(XANADU_DATABASE_LIBRARY libXanaduDatabase.dylib /usr/local/lib/)
elseif (UNIX)
	FIND_PATH(XANADU_DATABASE_LIBRARY libXanaduDatabase.so /usr/lib/)
endif ()

message("XANADU_DATABASE_INCLUDE: ${XANADU_DATABASE_INCLUDE}")
message("XANADU_DATABASE_LIBRARY: ${XANADU_DATABASE_LIBRARY}")

if(XANADU_DATABASE_INCLUDE AND XANADU_DATABASE_LIBRARY)
	# 设置变量结果
	set(XANADU_DATABASE_FOUND TRUE)
endif(XANADU_DATABASE_INCLUDE AND XANADU_DATABASE_LIBRARY)
