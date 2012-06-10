all: bindir bin/has_a bin/polymorphic_data_processing bin/polymorphic_data_processing_template bin/polymorphic_data_processing_template2 bin/functor

bindir: 
	mkdir -p bin

clean:
	if [ -e bin ]; then rm -rf bin/* && rmdir bin ; fi

bin/has_a: has_a.cpp
	g++ has_a.cpp -o bin/has_a -I/sandbox/vendor/boost/1_38_0/include
    
bin/functor: functor.cpp
	g++ functor.cpp -o bin/functor -I/sandbox/vendor/boost/1_38_0/include

bin/polymorphic_data_processing: polymorphic_data_processing.cpp
	g++ polymorphic_data_processing.cpp -m64 -o bin/polymorphic_data_processing -I/sandbox/vendor/boost/1_38_0/include

    
bin/polymorphic_data_processing_template: polymorphic_data_processing_template.cpp
	g++ polymorphic_data_processing_template.cpp -m64 -o bin/polymorphic_data_processing_template -I/sandbox/vendor/boost/1_38_0/include


bin/polymorphic_data_processing_template2: polymorphic_data_processing_template2.cpp
	g++ polymorphic_data_processing_template2.cpp -m64 -o bin/polymorphic_data_processing_template2 -I/sandbox/vendor/boost/1_38_0/include




