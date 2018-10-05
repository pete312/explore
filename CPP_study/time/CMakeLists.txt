
set(PROGRAMS test_dateint gmtime)


foreach( program ${PROGRAMS})
	add_executable(${program} ${program}.cpp)
	target_link_libraries( ${program} ${Boost_SYSTEM_LIBRARY} )
endforeach(program)
