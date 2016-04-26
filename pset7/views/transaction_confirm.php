<?php
setlocale(LC_MONETARY, 'en_US');
?>

Your transaction is complete!


<table align="center" class="table">
    <tr>
        <td>Company</td>
        <td width=2%>&nbsp;</td>
        <td><b><?= htmlspecialchars($name) ?></b></td>
    </tr>
    <tr>
        <tr>
        <td>Price</td>
         <td width=2%>&nbsp;</td>
        <td><b>$<?= money_format('%(#10n', $price) ?><b></b></td>
    </tr>
    
    
        <tr>
        <tr>
        <td>Transaction Type</td>
         <td width=2%>&nbsp;</td>
        <td><b><?= htmlspecialchars($transaction_type) ?><b></b></td>
    </tr>
</table>