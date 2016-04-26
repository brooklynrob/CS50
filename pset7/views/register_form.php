<p>We are very generous - you will get $10,000 deposited to your account when your register!</p>

<form action="register.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autocomplete="off" autofocus class="form-control" name="username" placeholder="Username" type="text"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="password" placeholder="Password" type="password"/>
        </div>
        <!-- Added confirmation field -->
        <div class="form-group">
            <input class="form-control" name="confirmation" placeholder="Confirm Password" type="password"/>
        </div>
        
        <div class="form-group">
            <input class="form-control" name="email" placeholder="Email Address" type="text"/>
        </div>
        
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                Log In
            </button>
        </div>
    </fieldset>
</form>
<div>
    or <a href="login.php">log in</a> to an existing account
</div>
