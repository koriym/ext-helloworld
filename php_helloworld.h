#ifndef PHP_HELLOWORLD_H // If PHP_HELLOWORLD_H is not defined
#define PHP_HELLOWORLD_H // Define PHP_HELLOWORLD_H (header guard)

extern zend_module_entry helloworld_module_entry;  // Declare helloworld module entry as external reference
#define phpext_helloworld_ptr &helloworld_module_entry  // Define pointer to helloworld module

#define PHP_HELLOWORLD_VERSION "0.1.0" // Define helloworld extension version

#ifdef PHP_WIN32  // If in Windows environment
#define PHP_HELLOWORLD_API __declspec(dllexport)  // Specify DLL export
#elif defined(__GNUC__) && __GNUC__ >= 4  // If using GCC 4 or later
#define PHP_HELLOWORLD_API __attribute__ ((visibility("default")))  // Specify default visibility
#else  // For other environments
#define PHP_HELLOWORLD_API  // No specific definition
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_FUNCTION(helloworld); // helloworld() function

// Function declarations
PHP_MINIT_FUNCTION(helloworld); // Module initialization function
PHP_MSHUTDOWN_FUNCTION(helloworld); // Module shutdown function
PHP_MINFO_FUNCTION(helloworld);  // Module information function

#ifdef ZTS  // If in thread-safe mode
#define HELLOWORLD_G(v) TSRMG(helloworld_globals_id, zend_helloworld_globals *, v)  // Global variable access macro (thread-safe version)
#else // If in non-thread-safe mode
#define HELLOWORLD_G(v) (helloworld_globals.v)  // Global variable access macro (non-thread-safe version)
#endif

#endif  /* PHP_HELLOWORLD_H */
