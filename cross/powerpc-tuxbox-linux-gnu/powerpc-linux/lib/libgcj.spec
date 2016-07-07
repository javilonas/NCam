#
# This spec file is read by gcj when linking.
# It is used to specify the standard libraries we need in order
# to link with libgcj.
#
%rename lib liborig
*lib: -lgcj -lm   -lpthread    -ldl %(libgcc) %(liborig)

*jc1: -fhash-synchronization -fuse-divide-subroutine  -fuse-boehm-gc -fnon-call-exceptions   -fkeep-inline-functions
