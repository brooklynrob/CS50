
 

<div>
    <!--<iframe allowfullscreen frameborder="0" height="315" src="https://www.youtube.com/embed/6gNnXfGd6WQ?autoplay=1&iv_load_policy=3&rel=0" width="420"></iframe>-->
    
    <table  class="table">
    <tr>
        <th>Symbol</th>
 
        <th>Shares Owned</th>
    
        <th>Current Price</th> 
        <th colspan = "2" align="center">Quick Sell</th>

        
    </tr>
    

        
<?php

        foreach ($positions as $position)
        {
        
            if ($position["shares"] > 0)
            {
            



?>
            
            
            
            
<?php
            
            print("<tr>");
            print("<td>{$position["symbol"]}</td>");
     
            print("<td>{$position["shares"]}</td>");
     
            print("<td>{$position["price"]}</td>");
?>
            
   
            <form action="transact.php" method="post">   
            
            <input type="hidden" name="ticker_symbol" value="<?php echo $position["symbol"];?>" />
            <input type="hidden" name="transaction_type" value="SELL" />
 
            
            <td>
                <div class="form-group">
                    <input autocomplete="off" autofocus class="form-control" name="shares" placeholder="Amount of Shares" type="text"/>
                </div>
            </td>

            <td>
                <div class="form-group">
                    <button class="btn btn-default" type="submit">
                    <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                    SELL
                    </button>
                    </form>
            </td>
            </tr>
           
           
<?php 
            }
        
            

 
            
            
            
        }
        
        print("<tr>");
        $available_cash = number_format($available_cash, 2, '.', '');
        print("<td colspan=5>Cash Available: &#36;&nbsp;{$available_cash}</td>");
?>
  

    </tr>
    </form>
    </table>



</div>
