<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_request.php", ["title" => "Quote Request"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["ticker_symbol"]))
        {
            apologize("You must provide a ticket symbol");
        }
  
  
        $stock = lookup($_POST["ticker_symbol"]);

        if ($stock !== false)
        {
       
      
      
        
        render("quote_display.php", ["name" => $stock["name"],"price" => $stock["price"]]);
        
   
        
        
        //render("quote_request.php", ["name" => $stock["name"]],["price" => $stock["price"]]]);
        //render("quote_display.php", ["name" => "Yahoo"]);
        
        }
        
        else
        {
            apologize("Stock Ticker not found");  
        }
    }

        


?>
