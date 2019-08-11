# Set for debugging purposes
# Possible flags:
# -DDEBUG : General debugging
# -DEVENT_DEBUG : Event queue debugging
# -DEVENT_PROFILE : Event queue profiling
#
DEBUGDEFS = 

INCLUDES = -I$(top_srcdir) -I.. $(DEBUGDEFS)

lib_LTLIBRARIES = libfreehdl-kernel.la
libfreehdl_kernel_la_LDFLAGS = -version-info 0:0
libfreehdl_kernel_la_LIBADD = $(REGEXLIBS)
libfreehdl_kernel_la_CXXFLAGS = $(REGEXDEFS)

libfreehdl_kernel_la_SOURCES = error.cc			\
	                       stack_trace.cc           \
	                       name_stack.cc		\
	                       attributes.cc		\
	                       process_base.cc		\
	                       sig_info.cc		\
	                       sigacl_list.cc		\
	                       wait_info.cc		\
	                       acl.cc			\
	                       main.cc			\
	                       handle.cc		\
	                       reader_info.cc		\
	                       driver_info.cc		\
	                       map_list.cc		\
	                       global_event_queue.cc	\
	                       kernel_class.cc          \
	                       dump.cc          	\
	                       resolver_process.cc      \
			       resolver_descriptor.cc	\
			       source_descriptor.cc	\
			       signal_source_list_array.cc \
	                       persistent_dump.cc       \
			       persistent_cdfg_dump.cc	\
	                       register.cc              \
			       db.cc			\
			       fhdl_stream.cc		\
                               pcounter.cc

CLEANFILES = *~
MAINTAINERCLEANFILES = Makefile.in
