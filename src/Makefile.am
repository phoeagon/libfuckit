lib_LIBRARIES = libfuckit.a
include_HEADERS = fuckit.h
check_PROGRAMS = fuckit fuckitcxx fuckitdyn 

AM_CFLAGS = $(UDIS86_CFLAGS)

fuckit_SOURCES = main.c fuckit.h
fuckit_LDFLAGS =
fuckit_LDADD = libfuckit.a -ludis86 -ldl 

fuckitcxx_SOURCES = main2.cpp fuckit.h
fuckitcxx_LDFLAGS =
fuckitcxx_LDADD = libfuckit.a -ludis86 -ldl

fuckitdyn_SOURCES = main_dyn.c fuckit.h
fuckitdyn_CFLAGS = -Ddynamic
fuckitdyn_LDFLAGS =
fuckitdyn_LDADD = libfuckit.a -ludis86 -ldl

libfuckit_a_SOURCES = fuckit.c fuckit.h fuckit_dyn.c fuckit_dyn_generated.h
libfuckit_a_CFLAGS = -Ddynamic -fPIC
libfuckit_a_LIBADD =

