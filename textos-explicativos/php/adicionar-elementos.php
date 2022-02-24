<?php

// Create

$id = "";
$hp = "";
$type = "";
$attack = "";
$defense = "";

$html = <<<END
    <form method="post" action="salvar.php">
        <input type="hidden" name="id">
        Type: <input type="text" name="type"><br/>
        HP: <input type="text" name="hp""><br/>
        Attack: <input type="text" name="attack"><br/>
        Defense: <input type="text" name="defense"><br/>
        <input type="submit" value="Salvar">
    </form>
END;
echo $html;
