
set(PROGRAMS  has_a polymorphic_data_processing polymorphic_data_processing_template functor polymorphic_data_processing_template2)



foreach( program ${PROGRAMS})
	add_executable(${program} ${program}.cpp)
	target_link_libraries( ${program} ${Boost_SYSTEM_LIBRARY} )
endforeach(program)
