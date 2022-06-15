cmake_minimum_required( VERSION 3.0 ) 

project( typhoon )
#find_package( PkgConfig )

# flags

# include files for this project
include_directories( ./include ./src )

# target
add_executable( typhoon 
		./src/main.cpp 
		./src/particle.cpp )	# further cpp sources may be added here

# 3rd party libs

