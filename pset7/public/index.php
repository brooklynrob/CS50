<?php

    // configuration
    require("../includes/config.php"); 

    // SELECT id, user_id, symbol, shares FROM portfolios WHERE user_id = 9
    $rows = CS50::query("SELECT id, user_id, symbol, shares FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
    $positions = [];
    
    if ($rows == NULL)
    {
        $positions[0] = [
            "name" => " ",
            "price" => " ",
            "shares" => " ",
            "symbol" => " "
            ];
    
    
    }
    else {
        foreach ($rows as $row)
        {
            $stock = lookup($row["symbol"]);
            if ($stock !== false)
            {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
            ];
            }
        }

        
    }
    
    $cash = CS50::query("SELECT cash from users WHERE id = ?", $_SESSION["id"]);
    
    if ($cash == 0)
    {
        $available_cash = 0;
    }
    else
    {
       
        $available_cash = $cash[0]["cash"];
    }

    render("portfolio.php", ["positions" => $positions, "available_cash" => $available_cash, "title" => "Portfolio"]);
    
    
   
   
   //Original
   //render("portfolio.php", ["cash" => 10000.00, "title" => "Portfolio"]);
?>
