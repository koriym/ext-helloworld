PHP_ARG_ENABLE(helloworld, whether to enable helloworld support,
[ --enable-helloworld   Enable helloworld support])

if test "$PHP_HELLOWORLD" != "no"; then
    PHP_NEW_EXTENSION(helloworld, helloworld.c, $ext_shared)
fi