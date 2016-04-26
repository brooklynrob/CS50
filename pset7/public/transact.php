<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("transaction_request.php", ["title" => "Sell or Buy Shares"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["ticker_symbol"]))
        {
            apologize("You must provide a ticket symbol");
        }
        
        if (empty($_POST["shares"]))
        {
            apologize("You must enter a number of shares");
        }
        
        if (preg_match("/^\d+$/", $_POST["shares"])!=TRUE)
        {
            apologize("You must enter a postive whole number of transactions");
        }
                
        if (empty($_POST["transaction_type"]))
        {
            apologize("You do not appear to have chosen a transaction types");
        }
  
    
  
        $stock = lookup(strtoupper($_POST["ticker_symbol"]));

        if ($stock !== false)
        {
       
        $shares_transacted = $_POST["shares"];
        // Calculate transcation cost     
        $transaction_cost = $shares_transacted * $stock["price"];
        
        // Get available cash
        $user_info = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        $user_cash = $user_info[0]["cash"];
        

        // Get user current shares
        $user_current_ownership = CS50::query("SELECT shares FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], strtoupper($_POST["ticker_symbol"]));
        
        if ($user_current_ownership == NULL) 
        //if (($user_current_ownership == NULL) || ($user_current_ownership[0]["shares"] <= 0))
        {
            $user_current_shares = 0;
            $user_current_stock = FALSE;
        }
        else
        {
            $user_current_shares = $user_current_ownership[0]["shares"];
            $user_current_stock = TRUE;
        }
        
        
        // IF SELL, CHECK ENOUGH SHARES
        if ($user_current_shares < $_POST["shares"] && $_POST["transaction_type"]=="SELL")
        {
            apologize("You do not have enough shares to sell that many shares");
        }

        

        // IF BUY, CHECK ENOUGH CASH
        if ($user_cash < $transaction_cost && $_POST["transaction_type"]=="BUY")
        {
            apologize("You do not have enough cash to make that sales");
        }
        
      
        
        // Now commit transaction
        
        // Update Cash
        
        if ($_POST["transaction_type"]=="BUY")
        {
            $transaction_cost = -$transaction_cost;
        }
        
        
        //UPDATE users SET cash = cash + 500 WHERE id = 9
        // EXAMPLE UPDATE users SET cash = cash + 500 WHERE id = 9
        //dump();
        $user_info = CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $transaction_cost, $_SESSION["id"]);
        
        if ($_POST["transaction_type"]=="SELL")
        {
            $shares_transacted = -$shares_transacted;
        }
        
        
        $user_current_ownership = CS50::query("UPDATE portfolios SET shares = shares + ? WHERE user_id = ? AND symbol = ?", $shares_transacted, $_SESSION["id"], strtoupper($_POST["ticker_symbol"]));
            
        if ($user_current_ownership == 0)
        {
            $user_current_ownership = CS50::query("INSERT IGNORE INTO portfolios (shares, symbol, user_id) VALUES(?, ?, ?)", $shares_transacted, strtoupper($_POST["ticker_symbol"]), $_SESSION["id"]);
        }
   
 
        
        $history = CS50::query("INSERT IGNORE INTO history (user_id, transaction_type, symbol, shares, price,transaction_cost) VALUES(?, ?, ?, ?, ?, ?)", $_SESSION["id"], $_POST["transaction_type"],strtoupper($_POST["ticker_symbol"]),$shares_transacted,$stock["price"],$transaction_cost);

      
        
        render("transaction_confirm.php", ["name" => $stock["name"],"price" => $stock["price"],"transaction_type" => $_POST["transaction_type"]]);
        

        
        
        //render("quote_request.php", ["name" => $stock["name"]],["price" => $stock["price"]]]);
        //render("quote_display.php", ["name" => "Yahoo"]);
        
        }
        
        else
        {
            apologize("Stock Ticker not found");  
        }
    }

        


?>
