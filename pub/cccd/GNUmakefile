defines:= -DCCCD_PORT=$(shell ./port.sh) \
	  -DCCCD_TRIES=5 \
          -DCCCD_REAP=5 \
	  -DCCCD_ERRFILE=\"errfile\"

ldflags=-lpthread
# or, maybe: ldflags=-pthread

include ../GNUmakefile
