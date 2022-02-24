<?php

// Update

include "config.php";
$conexao = mysqli_connect($host, $usuario, $senha, "rpg");
if (!$conexao) {
    echo mysqli_connect_error();
    die();
}

$id = $_REQUEST["id"];

if (!empty($id)) {
    $consulta = "SELECT * FROM enemy WHERE id = $id";
    $resultado_da_consulta = mysqli_query($conexao, $consulta);
    
    if (!$resultado_da_consulta) {
        echo "Erro na consulta: $consulta";
        echo mysqli_error($conexao);
        mysqli_close($conexao);
        die();
    }

    $linha = mysqli_fetch_assoc($resultado_da_consulta);

    if ($linha) {
        $id = $linha["id"];
        $hp = $linha["HP"];
        $type = $linha["type"];
        $attack = $linha["attack"];
        $defense = $linha["defense"];

        $html = <<<END
            <form method="post" action="salvar.php">
                <input type="hidden" name="id" value="$id">
                Type: <input type="text" name="type" value="$type"><br/>
                HP: <input type="text" name="hp" value="$hp"><br/>
                Attack: <input type="text" name="attack" value="$attack"><br/>
                Defense: <input type="text" name="defense" value="$defense"><br/>
                <input type="submit" value="Salvar">
            </form>
END;
        echo $html;
    }
}

mysqli_free_result($resultado_da_consulta);
mysqli_close();
