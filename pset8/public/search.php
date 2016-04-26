<?php
    header('Access-Control-Allow-Origin: https://event-tickets-tracker-runderwood5.cs50.io');
    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];
    
    
    // regex derived from http://stackoverflow.com/questions/21074812/extracting-a-zip-code-from-an-address-string
    
    // If a ZIP can be extracted and there is an exact match
    if(preg_match('/(^\d{5}$)|(^\d{5}-\d{4}$)/',$_GET["geo"],$postal_code))
    {
        $places = CS50::query("SELECT * FROM places WHERE postal_code = ?", $_GET["geo"]);
    }
    else
    {
        $places = CS50::query("SELECT * FROM places WHERE place_name LIKE ?", $_GET["geo"] . "%");
        //$places = CS50::query("SELECT * FROM places WHERE MATCH(postal_code, place_name) AGAINST (?)", $_GET["geo"]);

    }
    
    //$places = CS50::query("SELECT * FROM places_test WHERE postal_code = ?", $_GET["geo"]);
    //$places = CS50::query("SELECT * FROM places_test WHERE MATCH(postal_code, place_name) AGAINST (?)", $_GET["geo"]);

    // TODO: search database for places matching $_GET["geo"], store in $places

    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));
    
//echo ("postal code is {$postal_code[0]} \n");

?>