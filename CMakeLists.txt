
cmake_minimum_required	(VERSION 3.6)

message(STATUS "*** Building Indie Studio version ${VERSION_STRING} // Salty Queens' Bomberman! ***")

project(indie_studio) #NOM DU PROJET

set			(IRRLICHT Irrlicht)
set 		(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build")

#set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE}) #LA Où ON VEUT SORTIR LE BINAIRE (facultatif)

file(
    GLOB_RECURSE
    sources_files #Nom de la Variable contenant les Dossiers
    src/* #Dossier contenant des fichiers( "*" pour dire tous les fichiers)
)

add_executable(
    bomberman #Nom de l'executable
    ${sources_files} #Variable contenant les Dossiers qui eux contiennes des fichiers
)
include_directories	(include)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")


if(WIN32)
	set(SHAREDIR ".")
	set(BINDIR "bin")
	set(CMAKE_CXX_FLAGS "-EHsc")

elseif(UNIX)
	set(SHAREDIR ".")
	set(BINDIR "bin")
	set(CMAKE_CXX_FLAGS "-W -Wextra -Werror")
	set(IRRLICHT_DEPENDENCIES Irrlicht X11 Xxf86vm pthread GL)
	install(DIRECTORY ${CMAKE_SOURCE_DIR}/cmake/lib/irrlicht-includes 
		DESTINATION /usr/include
		FILE_PERMISSIONS WORLD_READ WORLD_WRITE
	)
	install(FILES ${CMAKE_SOURCE_DIR}/cmake/lib/Unix/libIrrlicht.a
		DESTINATION /usr/lib
	)
	add_custom_target (fclean @echo cleaning for source distribution)
	add_custom_command(
		COMMENT "CLEAN DIRECTORY"
		COMMAND make
        # ARGS -C ${CMAKE_CURRENT_BINARY_DIR} clean
        COMMAND find
        ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "CMakeCache.txt" | xargs rm -rf
        COMMAND find
        ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "CMakeFiles" | xargs rm -rf
        COMMAND find
        # ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "Makefile" | xargs rm -rf
        # COMMAND find
        ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "*.cmake" | xargs rm -rf
        TARGET  fclean
	)
endif()

find_package(Irrlicht)

if(IRRLICHT_FOUND)
	message(STATUS "*** Irrlicht ***")
	
	if(WIN32)
		include_directories(${IRRLICHT_INCLUDE_DIR})
		target_link_libraries(bomberman
					${IRRLICHT_DEPENDENCIES}
					${IRRLICHT_LIBRARY}
					)
		file(COPY ${IRRLICHT_DLL} DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/build/Debug")
		file(COPY ${IRRLICHT_LIBRARY} DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/Debug")	
	else()
		include_directories(${IRRLICHT_INCLUDE_DIR})
		target_link_libraries(bomberman ${IRRLICHT_DEPENDENCIES} ${IRRLICHT_LIBRARY})
	endif()

	set_property		(TARGET bomberman PROPERTY CXX_STANDARD 11)
	message(STATUS "*** Successfully generated Salty Queens' Bomberman project! ***")
else()
	message(WARNING "*** Irrlicht not found, build failed! ***")
endif()
