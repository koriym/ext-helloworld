# HelloWorld PHP Extension

A simple PHP extension that demonstrates basic and advanced "Hello World" functionality.

## Features

- Basic `helloworld()` function
- Advanced `helloworld_advanced()` function with configurable greeting

## Run

1. Compile the extension:

    ```
    // make clean
    // phpize --clear
    phpize
    ./configure --enable-helloworld --enable-helloworld-advanced
    make
    ```

2. Run

    ```
    % php -d extension=./modules/helloworld.so -i | grep hello

    helloworld
    helloworld support => enabled
    helloworld.greeting => Hello World! => Hello World!

    % php -d extension=./modules/helloworld.so php/helloworld.php
    Hello World!
    Hello World!
   ```

## Usage

### Basic Function

```php
<?php
helloworld();
// Output: Hello World!
```

### Advanced Function

```php
<?php
helloworld_advanced();
// Output: [Configurable greeting from php.ini]
?>
```

To configure the greeting, add the following to your php.ini:

```
helloworld.greeting = "Your custom greeting!"
```
