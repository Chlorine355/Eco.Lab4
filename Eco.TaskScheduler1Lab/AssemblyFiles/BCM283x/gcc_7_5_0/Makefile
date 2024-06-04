ifeq ($(OS), Windows_NT)
	#WINDOWS USE THESE DEFINITIONS
	RM = -rm -f
	SLASH = \\
	SWALLOW_OUTPUT = >nul 2>nul
else
	#LINUX USE THESE DEFINITIONS
	RM = -rm -f
	SLASH = /
	SWALLOW_OUTPUT =
endif 

# include directories
INC = \
-I ../../../HeaderFiles \
-I ../../../SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Core1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.InterfaceBus1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Timer1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.MemoryManager1/SharedFiles

# source files.
SRC = \
..$(SLASH)..$(SLASH)..$(SLASH)SourceFiles$(SLASH)CEcoTask1Lab.c \
..$(SLASH)..$(SLASH)..$(SLASH)SourceFiles$(SLASH)CEcoTaskScheduler1Lab.c \
..$(SLASH)..$(SLASH)..$(SLASH)SourceFiles$(SLASH)CEcoTaskScheduler1LabFactory.c

OBJ = $(SRC:.c=.o)

OUT = lib902ABA722D34417BB714322CC761620F.a
OUT_DIR = ..$(SLASH)..$(SLASH)..$(SLASH)BuildFiles$(SLASH)BCM283x$(SLASH)arm64-v8a$(SLASH)StaticRelease

 
# C++ compiler flags (-g -O2 -Wall)
CCFLAGS = -Wall -std=gnu89 -Wno-missing-braces -march=armv8-a+simd -mtune=cortex-a53 -mstrict-align -fno-tree-loop-vectorize -fno-tree-slp-vectorize -DECO_BCM283X -DECO_LIB -DUGUID_UTILITY
 
# compiler
ARMGNU  = $(ECO_TOOLCHAIN)/gcc-linaro-7.5.0/bin/
CCC = $(ARMGNU)aarch64-elf-gcc
 
# library paths
LIBS = -lc -lm -lgcc
 
# compile flags
LDFLAGS =
 
.SUFFIXES: .c

all: $(OUT)

.c.o:
	$(CCC) $(INC) $(CCFLAGS) -c $< -o $@
 
$(OUT): $(OBJ)
	$(ARMGNU)aarch64-elf-ar -rcs $(OUT_DIR)$(SLASH)$(OUT) $(OBJ)
 

clean:
	$(RM) $(OBJ) $(OUT_DIR)$(SLASH)$(OUT)
