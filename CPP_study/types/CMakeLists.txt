
set(PROGRAMS overloads epsilon templates conversions generic format2 enumtype cast passing_args shortcut typeid )


foreach( program ${PROGRAMS})
	add_executable(${program} ${program}.cpp)
	target_link_libraries( ${program} ${Boost_SYSTEM_LIBRARY} )
endforeach(program)
