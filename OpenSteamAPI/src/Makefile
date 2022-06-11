UNAME := $(shell uname)
UNAME_M := $(shell uname -m)
BUILD_ARCH := 32
CXX = g++

ifeq ($(UNAME_M), x86_64)
	BUILD_ARCH := 64
endif

ifeq ($(UNAME_M), arm64)
	BUILD_ARCH := 64
endif

FLAGS = -m$(BUILD_ARCH) -fPIC -O2 -c -I../../OpenSteamworks

LIBNAME = ../lib/Linux$(BUILD_ARCH)/OpenSteamAPI.a
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
