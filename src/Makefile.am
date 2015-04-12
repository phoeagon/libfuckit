bin_PROGRAMS = fuckit fuckitcxx fuckitdyn

AM_CFLAGS = $(UDIS86_CFLAGS)

fuckit_SOURCES = main.c fuckit.c fuckit.h
fuckit_LDFLAGS =
fuckit_LDADD = -ludis86

fuckitcxx_SOURCES = main2.cpp fuckit.c fuckit.h
fuckitcxx_LDFLAGS =
fuckitcxx_LDADD = -ludis86

fuckitdyn_SOURCES = main_dyn.c fuckit.c fuckit.h fuckit_dyn.c
fuckitdyn_CFLAGS = -Ddynamic
fuckitdyn_LDFLAGS =
fuckitdyn_LDADD = -ludis86 -ldl
