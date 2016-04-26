<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO
        // validate submission
        if (empty($_POST["username"]))
        {
            apologize("You must provide a username.");
        }
        else if (empty($_POST["password"]))
        {
            apologize("You must provide a password.");
        }
        else if (empty($_POST["confirmation"]))
        {
            apologize("You must confirm your password");
        }
        else if (($_POST["password"]) != ($_POST["confirmation"]))
        {
            apologize("Passwords Must Match");
        }
        
        else if (empty($_POST["email"]))
        {
            apologize("Please provide an email");
        }
        
        
        // Following code credit http://stackoverflow.com/questions/12026842/how-to-validate-an-email-address-in-php
        else if (!filter_var($_POST["email"], FILTER_VALIDATE_EMAIL))
        {
            apologize("Does not appear to be a valid email");
        }
        
        
        
        
        // create SQL statement to insert user
        $insert_result = CS50::query("INSERT IGNORE INTO users (username, email, hash, cash) VALUES(?, ?, ?, 10000.0000)", $_POST["username"], $_POST["email"], password_hash($_POST["password"], PASSWORD_DEFAULT));
        
        if ($insert_result == 0)
        {
            apologize("Whoops! Something went wrong");
        }
        
        else
        {
                $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
                //$rows = CS50::query("SELECT * FROM users WHERE username = ?", $_POST["username"]);
                $id = $rows[0]["id"];
                // remember that user's now logged in by storing user's ID in session
                $_SESSION["id"] = $id;

                // redirect to portfolio
                redirect("/");
        }
        
    
    }    
 

?>