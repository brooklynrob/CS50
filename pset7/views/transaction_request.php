
<h1>Sell</h1>
<form action="transact.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autocomplete="off" autofocus class="form-control" name="ticker_symbol" placeholder="Stock Ticker Symbol" type="text"/>
        </div>
        
        <div class="form-group">
            <input autocomplete="off" autofocus class="form-control" name="shares" placeholder="Amount of Shares" type="text"/>
        </div>
   
   
        
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                SELL
            </button>
        </div>
    </fieldset>
        <input type="hidden" name="transaction_type" value="SELL" />
</form>

<h2>Buy</h2>

<form action="transact.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autocomplete="off" autofocus class="form-control" name="ticker_symbol" placeholder="Stock Ticker Symbol" type="text"/>
        </div>
        
        <div class="form-group">
            <input autocomplete="off" autofocus class="form-control" name="shares" placeholder="Amount of Shares" type="text"/>
        </div>
   
   
        
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                BUY
            </button>
        </div>
    </fieldset>
        <input type="hidden" name="transaction_type" value="BUY" />
</form>