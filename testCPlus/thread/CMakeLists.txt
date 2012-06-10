
set(PROGRAMS thread_test)
#set(PROGRAMS signal_example thread_test)


foreach( program ${PROGRAMS})
	add_executable(${program} ${program}.cpp)
	target_link_libraries( ${program} ${Boost_SYSTEM_LIBRARY} )
endforeach(program)
