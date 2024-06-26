/*
  +----------------------------------------------------------------------+
  | PHP Extension for advanced "Hello World" functionality               |
  +----------------------------------------------------------------------+
  | Copyright (c) 2024 Akihito Koriyama                                  |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* Define that we're using advanced features */
#define HELLOWORLD_ADVANCED 1

/* Include necessary headers */
#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_helloworld.h"

/* Declare module globals */
ZEND_DECLARE_MODULE_GLOBALS(helloworld)

ZEND_DECLARE_MODULE_GLOBALS(helloworld)

/* Define INI entries */
PHP_INI_BEGIN()
    /* Define a configurable greeting message */
    STD_PHP_INI_ENTRY("helloworld.greeting", "Hello World!", PHP_INI_ALL, OnUpdateString, greeting, zend_helloworld_globals, helloworld_globals)
PHP_INI_END()

/* Argument info for helloworld function (no arguments) */
ZEND_BEGIN_ARG_INFO(arginfo_helloworld, 0)
ZEND_END_ARG_INFO()

/* Argument info for helloworld_advanced function (no arguments) */
ZEND_BEGIN_ARG_INFO(arginfo_helloworld_advanced, 0)
ZEND_END_ARG_INFO()

/* Implementation of helloworld function */
PHP_FUNCTION(helloworld)
{
    ZEND_PARSE_PARAMETERS_NONE();

    php_printf("Hello World!\n");
}

/* Implementation of helloworld_advanced function */
PHP_FUNCTION(helloworld_advanced)
{
    ZEND_PARSE_PARAMETERS_NONE();

    /* Print the configurable greeting message */
    php_printf("%s\n", HELLOWORLD_G(greeting));
}

/* Module initialization function */
PHP_MINIT_FUNCTION(helloworld)
{
    /* Register INI entries */
    REGISTER_INI_ENTRIES();
    return SUCCESS;
}

/* Module shutdown function */
PHP_MSHUTDOWN_FUNCTION(helloworld)
{
    /* Unregister INI entries */
    UNREGISTER_INI_ENTRIES();
    return SUCCESS;
}

/* Function for phpinfo() output */
PHP_MINFO_FUNCTION(helloworld)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "helloworld support", "enabled");
    php_info_print_table_row(2, "Version", PHP_HELLOWORLD_VERSION);
    php_info_print_table_end();

    /* Display INI entries */
    DISPLAY_INI_ENTRIES();
}

/* List of functions provided by this extension */
const zend_function_entry helloworld_functions[] = {
    PHP_FE(helloworld, arginfo_helloworld)
    PHP_FE(helloworld_advanced, arginfo_helloworld_advanced)
    PHP_FE_END  /* Must be the last line */
};

/* Module entry */
zend_module_entry helloworld_module_entry = {
    STANDARD_MODULE_HEADER,
    "helloworld",               /* Extension name */
    helloworld_functions,       /* Function entries */
    PHP_MINIT(helloworld),      /* Module initialization */
    PHP_MSHUTDOWN(helloworld),  /* Module shutdown */
    NULL,                       /* Request initialization */
    NULL,                       /* Request shutdown */
    PHP_MINFO(helloworld),      /* Module information */
    PHP_HELLOWORLD_VERSION,     /* Version number */
    STANDARD_MODULE_PROPERTIES
};

/* Compile as a dynamic module */
#ifdef COMPILE_DL_HELLOWORLD
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(helloworld)
#endif
