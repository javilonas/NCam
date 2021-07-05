#undef SYSROOT_SUFFIX_SPEC
#define SYSROOT_SUFFIX_SPEC "" \
"%{mthumb:" \
  "%{mcpu=marvell-pj4|march=armv7|march=armv7-a|march=armv7-r|march=armv7-m|mcpu=marvell-fv7|mcpu=marvell-pj4b|mcpu=marvell-pj4c|mcpu=marvell-whitney|mcpu=cortex-a9|mcpu=cortex-a8|mcpu=cortex-a5|mcpu=cortex-r4|mcpu=cortex-r4f|mcpu=cortex-m3:/thumb2;" \
  ":};" \
":}"
