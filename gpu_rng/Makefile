################################################################################
#
#  Copyright (c) 2007 A. Arnold and J. A. van Meel, FOM institute
#  AMOLF, Amsterdam; all rights reserved unless otherwise stated.
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  In addition to the regulations of the GNU General Public License,
#  publications and communications based in parts on this program or on
#  parts of this program are required to cite the article
#  "Harvesting graphics power for MD simulations"
#  by J.A. van Meel, A. Arnold, D. Frenkel, S. F. Portegies Zwart and
#  R. G. Belleman, Molecular Simulation, Vol. 34, p. 259 (2007).

#  This program is distributed in the hope that it will be useful, but
#  WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#  General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 59 Temple Place, Suite 330, Boston,
#  MA 02111-1307 USA
#
################################################################################
#
# \file   Makefile
# \date   2007-05
# \author J.A. van Meel
# \brief  Creates the mdgpu random number generator
#
################################################################################

# include local settings
include ../local.mk

# create a static library
STATIC_LIB := 

# create an application
APP := ../bin/mdgpu_rng

# Cuda source files (compiled with cudacc)
CUFILES		:= gpu.cu random.cu
CFILES		:= 
CPPFILES	:= main.cpp 

# cubin sub-directory
CUBIN_DIR   := cubin

# object sub-directory
OBJ_DIR     := obj

# library search paths
LIB_PATHS	:= -L$(CUDA_PATH)/lib

# include search paths
INC_PATHS	:=

# required libraries
LIBS		:= -lcudart

# compiler flags
CUFLAGS		:=
CFLAGS		:= -Wall $(INC_PATHS)
CPPFLAGS	:= -Wall $(INC_PATHS)
LFLAGS		:= $(LIB_PATHS)

################################################################################
# Transformations
################################################################################
OBJECTS	    := $(patsubst %.cu, $(OBJ_DIR)/%.o, $(CUFILES))
OBJECTS     += $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(CPPFILES))
OBJECTS     += $(patsubst %.c, $(OBJ_DIR)/%.o, $(CFILES))
CUBIN_FILES := $(patsubst %.cu, $(CUBIN_DIR)/%.cubin, $(CUFILES))

ifdef EMULATION
  CUFLAGS   += --device-emulation
  CFLAGS    += -D__DEVICE_EMULATION__
  CPPFLAGS  += -D__DEVICE_EMULATION__
endif

ifdef DEBUG
  CUFLAGS   += -G1
  CFLAGS    += -g
  CPPFLAGS  += -g
  LFLAGS    += -g
else
  CUFLAGS   += --use_fast_math
  CFLAGS    += -O2
  CPPFLAGS  += -O2
endif

################################################################################
# Rules and targets
################################################################################

.PHONY: all emu

all : $(OBJ_DIR) $(CUBIN_DIR) $(STATIC_LIB) $(APP)

emu :
	$(MAKE) EMULATION=1

$(OBJ_DIR):
	@mkdir $@

$(CUBIN_DIR):
	@mkdir $@

$(STATIC_LIB) : $(OBJECTS)
	nvcc --lib -o $@ $(CUFLAGS) $(OBJECTS)

$(APP) : $(OBJECTS)
	gcc -o $(APP) $(LFLAGS) $(OBJECTS) $(LIBS)

$(OBJ_DIR)/%.o : %.cu
	nvcc -c $(CUFLAGS) $<
	mv $(*F).o $(OBJ_DIR)/$(*F).o

$(OBJ_DIR)/%.o : %.c
	gcc -c $(CFLAGS) $<
	mv $(*F).o $(OBJ_DIR)/$(*F).o

$(OBJ_DIR)/%.o : %.cpp
	g++ -c $(CPPFLAGS) $<
	mv $(*F).o $(OBJ_DIR)/$(*F).o

$(CUBIN_DIR)/%.cubin : %.cu
	nvcc --cubin $<
	mv %.o $(CUBIN_DIR)/%.o

clean:
	rm -f $(OBJECTS) $(CUBIN_FILES)

tidy: clean
	rm -f $(STATIC_LIB) $(APP) *~
	rm -rf $(OBJ_DIR) $(CUBIN_DIR)
