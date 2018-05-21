include_directories(FILES
	inc/*	
)

file(SOURCE_FILE
	srv.c
)

add_executable(s SOURCE_FILE)
