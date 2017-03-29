#undef SYSROOT_SUFFIX_SPEC
#define SYSROOT_SUFFIX_SPEC "" \
"%{mthumb:" \
  "%{march=armv4t|march=ep9312|mcpu=arm7tdmi|mcpu=arm7tdmi-s|mcpu=arm710t|mcpu=arm720t|mcpu=arm740t|mcpu=arm9|mcpu=arm9tdmi|mcpu=arm920|mcpu=arm920t|mcpu=arm922t|mcpu=arm940t|mcpu=ep9312|march=armv5|march=armv5t|march=arm10tdmi|march=arm1020t:/armv4t;" \
  "march=armv7|march=armv7a|march=armv7r|march=armv7m|march=armv7-a|march=armv7-r|march=armv7-m|march=armv7e-m|mcpu=cortex-a9|mcpu=cortex-a8|mcpu=cortex-a5|mcpu=cortex-r4|mcpu=cortex-r4f|mcpu=cortex-r5|mcpu=cortex-m3:/thumb2;" \
  ":};" \
":" \
  "%{march=armv4t|march=ep9312|mcpu=arm7tdmi|mcpu=arm7tdmi-s|mcpu=arm710t|mcpu=arm720t|mcpu=arm740t|mcpu=arm9|mcpu=arm9tdmi|mcpu=arm920|mcpu=arm920t|mcpu=arm922t|mcpu=arm940t|mcpu=ep9312|march=armv5|march=armv5t|march=arm10tdmi|march=arm1020t:/armv4t;" \
  ":}}"
