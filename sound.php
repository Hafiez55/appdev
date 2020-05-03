
<?php
$peaks = $_POST['peaks'];
$max = $_POST['max'];
$today = date("Y-m-d H:i:s");
$record = $today.", There are ".$peaks." peaks & Maximum Value(dB) is ".$max."\n";
$file = "testsound.log";
if(file_exists($file))
    $fp = fopen($file,"a");
else
    $fp = fopen($file,"w");
fwrite($fp,$record);
fclose($fp);
?>

