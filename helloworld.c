#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_helloworld.h"

/* {{{ PHP_FUNCTION(helloworld) */
PHP_FUNCTION(helloworld)
{
    php_printf("Hello World!\n");
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(helloworld)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "helloworld support", "enabled");
    php_info_print_table_end();
}
/* }}} */

/* {{{ arginfo */
ZEND_BEGIN_ARG_INFO(arginfo_helloworld, 0)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ helloworld_functions[] */
const zend_function_entry helloworld_functions[] = {
    PHP_FE(helloworld, arginfo_helloworld)
    PHP_FE_END
};
/* }}} */

/* {{{ helloworld_module_entry */
zend_module_entry helloworld_module_entry = {
    STANDARD_MODULE_HEADER,
    "helloworld",
    helloworld_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    PHP_MINFO(helloworld),
    PHP_HELLOWORLD_VERSION,
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_HELLOWORLD
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(helloworld)
#endif