<?php
    header('Access-Control-Allow-Origin: https://event-tickets-tracker-runderwood5.cs50.io');
    require(__DIR__ . "/../includes/config.php");

    // ensure proper usage
    if (empty($_GET["geo"]))
    {
        http_response_code(400);
        exit;
    }

    // get geography's articles
    $articles = lookup($_GET["geo"]);

    // output articles as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($articles, JSON_PRETTY_PRINT));

?>