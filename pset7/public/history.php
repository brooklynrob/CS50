<?php

    // configuration
    require("../includes/config.php"); 

    // SELECT id, user_id, symbol, shares FROM portfolios WHERE user_id = 9
    $rows = CS50::query("SELECT transaction_type, symbol, shares, price, transaction_cost FROM history WHERE user_id = ?", $_SESSION["id"]);
 
 
    if ($rows == NULL)

    {
        $historys[0] = [
        "transaction_type" => " ",
        "symbol" => " ",
        "shares" => " ",
        "price" => "0.0000",
        "transaction_cost" => "0.0000"
        ];
    }
    
    else
    {
        $history = [];
        foreach ($rows as $row)
        {
            $stock = lookup($row["symbol"]);
            if ($stock !== false)
            {
            $historys[] = [
                "transaction_type" => $row["transaction_type"],
                "symbol" => $row["symbol"],
                "shares" => $row["shares"],
                "price" => $row["price"], 
                "transaction_cost" => $row["transaction_cost"]
            ];
            }
        }

    }
    render("history_display.php", ["historys" => $historys, "title" => "Transaction History"]);
    
 
   
?>
