<?php

    // From http://swiftdeveloperblog.com/send-http-post-request-example-using-swift-and-php/
    // Read request parameters
    $firstName= $_REQUEST["firstName"];
    $lastName = $_REQUEST["lastName"];// Store values in an array
    $returnValue = array(“firstName”=>$firstName, “lastName”=>$lastName);
    // Send back request in JSON format
    echo json_encode($returnValue);

?>