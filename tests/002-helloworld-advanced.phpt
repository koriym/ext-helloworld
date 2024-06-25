--TEST--
Check for helloworld_advanced function
--SKIPIF--
<?php
if (!extension_loaded("helloworld")) print "skip";
if (!function_exists("helloworld_advanced")) print "skip advanced features not enabled";
?>
--FILE--
<?php
helloworld_advanced();
?>
--EXPECT--
Hello World!
