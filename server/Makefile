#-*-Makefile-*-

TARGET = parisrv
SHELL  = /bin/sh
OS ?=

RM = rm -f

ifeq ($(OS),darwin)
DBGFLAGS   = -g -Wall
CFLAGS     = -O3 -Wall -fno-strict-aliasing -fomit-frame-pointer
EXTRACFLAGS=
#CFLAGS    = $(DBGFLAGS)

CC         = /usr/bin/gcc
CPPFLAGS   = -I. -I/usr/local/include
LD         = /usr/bin/gcc
LDFLAGS    = -O3 -Wall -fno-strict-aliasing -fomit-frame-pointer    -Wl,-search_paths_first 
MODLD      = /usr/bin/gcc
MODLDFLAGS = -bundle -flat_namespace -undefined suppress $(CFLAGS) $(DLCFLAGS)
EXTRAMODLDFLAGS = 
EXTRALIBS  =

RUNPTH     = 
DLCFLAGS   = -fPIC
LIBS       =  -L/usr/local/lib -lpari

RM = rm -f

OBJS = $(TARGET).o
DYN = lib$(TARGET).dylib
ALL = $(TARGET)-sta $(TARGET)-dyn $(DYN)

DYN = lib$(TARGET).so
else
DBGFLAGS   = -g -Wall
CFLAGS     = -O3 -Wall -fno-strict-aliasing -fomit-frame-pointer
EXTRACFLAGS=

CC         = /usr/bin/gcc
CPPFLAGS   = -I. -I/usr/local/include
LD         = /usr/bin/gcc
LDFLAGS    = -O3 -Wall -fno-strict-aliasing -fomit-frame-pointer    -Wl,--export-dynamic 
MODLD      = /usr/bin/gcc
MODLDFLAGS = -shared  $(CFLAGS) $(DLCFLAGS) -Wl,-shared 
EXTRAMODLDFLAGS = -lc -lm -L/usr/local/lib -lpari
EXTRALIBS  =

RUNPTH     = -Wl,-rpath "/usr/local/lib"
DLCFLAGS   = -fPIC
LIBS       = -lm -L/usr/local/lib -lpari

RM = rm -f

OBJS = $(TARGET).o
DYN = lib$(TARGET).so
ALL = $(TARGET)-sta $(TARGET)-dyn $(DYN)
endif

OBJS = $(TARGET).o

ALL = $(TARGET)-sta $(TARGET)-dyn $(DYN)

dft: $(TARGET)-dyn

all: $(ALL)

sta: $(TARGET)-sta

dyn: $(TARGET)-dyn

dynlib: $(DYN)

$(DYN): $(OBJS)
	$(MODLD) -o $@ $(MODLDFLAGS) $(EXTRACFLAGS) $(OBJS) $(EXTRAMODLDFLAGS)

$(TARGET)-sta: $(OBJS)
	$(LD) -o $@ $(LDFLAGS) $(EXTRACFLAGS) $< $(EXTRALIBS) $(STATIC) $(LIBS)

$(TARGET)-dyn: $(OBJS)
	$(LD) -o $@ $(LDFLAGS) $(EXTRACFLAGS) $< $(EXTRALIBS) $(RUNPTH) $(LIBS)

%.o: %.c
	$(CC) -c $(CFLAGS) $(EXTRACFLAGS) $(CPPFLAGS) $(DLCFLAGS) $<
clean:
	-$(RM) *.o $(ALL)
