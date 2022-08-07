UNAME := $(shell uname)
UNAME_M := $(shell uname -m)
WORD_LENGTH := 32
BUILD_ARCH := 32
CXX = g++

SYSTEM_OS := UNAME

ifeq ($(UNAME), Darwin)
	SYSTEM_OS := OSX
endif

ifeq ($(UNAME_M), x86_64)
	WORD_LENGTH := 64
	BUILD_ARCH := 64
endif

ifeq ($(UNAME_M), arm64)
	WORD_LENGTH := 64
	BUILD_ARCH := ARM64
endif

FLAGS = -m$(WORD_LENGTH) -fPIC -O2 -c -I../../OpenSteamworks

LIBNAME = ../lib/$(SYSTEM_OS)$(BUILD_ARCH)/OpenSteamAPI.a
SRCS = CCallbackMgr.cpp ClientWrap.cpp Interface_OSW.cpp

ifeq ($(UNAME), Darwin)
	SRCS += OSXPathHelper.mm
endif

all: objs
	ar rcsv $(LIBNAME) *.o

objs:
	$(CXX) $(FLAGS) $(SRCS)

clean:
	rm -f *.o *.a
