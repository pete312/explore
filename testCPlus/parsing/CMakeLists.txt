
set(PROGRAMS dateparse assemble c_str compare dress config_parse  )



foreach( program ${PROGRAMS})
	add_executable(${program} ${program}.cpp)
	target_link_libraries( ${program} ${Boost_SYSTEM_LIBRARY} )
endforeach(program)
