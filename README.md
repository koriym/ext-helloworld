# A PECL project skeleton

[![Build and Test PHP Extension](https://github.com/koriym/ext-helloworld/actions/workflows/build.yml/badge.svg)](https://github.com/koriym/ext-helloworld/actions/workflows/build.yml)

## HelloWorld PHP Extension

A simple PHP extension that demonstrates basic "Hello World" functionality.

## Run

1. Compile the extension:

    ```
    phpize
    ./configure
    make
    ```

2. Run

    ```
    % php -d extension=./modules/helloworld.so -i | grep hello

    helloworld
    helloworld support => enabled

    % php -d extension=./modules/helloworld.so smoke.php
    Hello World!
   ```

### Basic Function

```php
<?php
helloworld();
// Output: Hello World!
```

## Getting started with development

### Source build


After cloning, edit `hellworld.c` to change the message.

```c
php_printf("Hello World!\n");
```

Next, compile to build.

```
phpize
./configure
make
```

This will create `modules/helloworld.so`. Now let's give it a try!

```
php -d extension=./modules/helloworld.so smoke.php
```

When your message is displayed in the hellworld() function, you are done!🎉

### Continuous Integration

This project contains a GitHub action workflow file.
Make sure the project is built successfully by ushing it; CI also installs Valgrind and checks for memory leaks.

### IDE

This repository contains CmakeLists.txt, which Clion needs to understand the source code.
Development using an IDE is efficient and allows for debugging, including a backtrace.

Refer to [Developing a PHP extension in CLion](https://dev.to/jasny/developing-a-php-extension-in-clion-3oo1) for more information.