#ifndef PHP_HELLOWORLD_H
#define PHP_HELLOWORLD_H

extern zend_module_entry helloworld_module_entry;
#define phpext_helloworld_ptr &helloworld_module_entry

#define PHP_HELLOWORLD_VERSION "1.0"

typedef struct _zend_helloworld_globals {
    char *greeting;
} zend_helloworld_globals;

#ifdef PHP_WIN32
#   define PHP_HELLOWORLD_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#   define PHP_HELLOWORLD_API __attribute__ ((visibility("default")))
#else
#   define PHP_HELLOWORLD_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_FUNCTION(helloworld);

PHP_MINIT_FUNCTION(helloworld);
PHP_MSHUTDOWN_FUNCTION(helloworld);
PHP_MINFO_FUNCTION(helloworld);

#ifdef ZTS
#define HELLOWORLD_G(v) TSRMG(helloworld_globals_id, zend_helloworld_globals *, v)
#else
#define HELLOWORLD_G(v) (helloworld_globals.v)
#endif

#endif  /* PHP_HELLOWORLD_H */
