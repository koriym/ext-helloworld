--TEST--
Check for helloworld presence
--SKIPIF--
<?php if (!extension_loaded("helloworld")) print "skip"; ?>
--FILE--
<?php
echo "helloworld extension is available";
?>
--EXPECT--
helloworld extension is available
