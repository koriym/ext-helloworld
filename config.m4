PHP_ARG_ENABLE(helloworld, whether to enable helloworld support,
[  --enable-helloworld           Enable helloworld support])

PHP_ARG_ENABLE(helloworld_advanced, whether to enable advanced helloworld features,
[  --enable-helloworld-advanced  Enable advanced helloworld features], no, no)

if test "$PHP_HELLOWORLD" != "no"; then
  PHP_ADD_INCLUDE($ext_srcdir/include)

  if test "$PHP_HELLOWORLD_ADVANCED" = "yes"; then
    AC_DEFINE(HELLOWORLD_ADVANCED, 1, [Whether advanced helloworld features are enabled])
    PHP_NEW_EXTENSION(helloworld, src/helloworld_advanced.c, $ext_shared,, -DHELLOWORLD_ADVANCED=1)
  else
    PHP_NEW_EXTENSION(helloworld, src/helloworld.c, $ext_shared)
  fi
fi
