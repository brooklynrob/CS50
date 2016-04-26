
 

<div>
    <!--<iframe allowfullscreen frameborder="0" height="315" src="https://www.youtube.com/embed/6gNnXfGd6WQ?autoplay=1&iv_load_policy=3&rel=0" width="420"></iframe>-->
    
    <table align="center" class="table table-striped">
    <Tr>
        <th>Transaction Type</th>
        <th>&nbsp;</th>
        <th>Symbol</th>
        <th>&nbsp;</th>
        <th>Shares</th> 
        <th>&nbsp;</th>
          <th>Price</th> 
        <th>&nbsp;</th>
                <th>Cash Credit (Debit)</th> 
        <th>&nbsp;</th>
        
    </tr>
    


    <?php

        foreach ($historys as $history)
        {
            print("<tr>");
            print("<td>{$history["transaction_type"]}</td>");
            print("<td></td>");
            print("<td>{$history["symbol"]}</td>");
            print("<td></td>");
            print("<td>{$history["shares"]}</td>");
            print("<td></td>");
            $price = number_format($history["price"], 2, '.', '');
            print("<td>&#36;&nbsp;&nbsp;{$price}</td>");
            print("<td></td>");
            $transaction_cost = number_format($history["transaction_cost"], 2, '.', '');
            print("<td>&#36;&nbsp;&nbsp;{$transaction_cost}</td>");
            //print("</tr>");
        }

    ?>
  

    </table>



</div>
