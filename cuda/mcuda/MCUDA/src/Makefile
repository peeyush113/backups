# (c) 2008 The Board of Trustees of the University of Illinois.

SRCDIR=MCUDA_DIR/src
BUILDDIR=MCUDA_DIR/lib

AR=ar
RANLIB=ranlib
CC=USER_DEFINED_CC
MCUDA_TYPE=LIB_TYPE
INCLUDE_FLAGS=-IMCUDA_DIR/src -IMCUDA_DIR/include -ICUDA_INSTALL_DIR/include
ifeq ($(MCUDA_TYPE), omp)
  CFLAGS= -x c $(INCLUDE_FLAGS) -O3 -msse3 -vec-report=3 -i-static -openmp
else
  CFLAGS= -x c $(INCLUDE_FLAGS) -O3 
endif

MCUDAOBJS=$(BUILDDIR)/mcutil.o
ifeq ($(MCUDA_TYPE), pthread)
  MCUDAOBJS+=$(BUILDDIR)/mcuda_pthreads.o
else
  ifeq ($(MCUDA_TYPE), omp)
    MCUDAOBJS+=$(BUILDDIR)/mcuda_omp.o
  else
    MCUDAOBJS+=$(BUILDDIR)/mcuda_st.o
  endif
endif

MCUDALIB=$(BUILDDIR)/libmcuda.a



all : $(MCUDALIB) $(PARLIB)

clean:
	rm -f $(PAROBJS) $(MCUDAOBJS) $(TARGETONE)
	rm -f $(PARLIB) $(MCUDALIB)

$(BUILDDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -c $(CFLAGS) $^ -o $@

$(MCUDALIB) : $(MCUDAOBJS)
	$(AR) rc $@ $?
	$(RANLIB) $@

