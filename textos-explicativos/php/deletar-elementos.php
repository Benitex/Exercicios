<?php

include "config.php";
$conexao = mysqli_connect($host, $usuario, $senha, "rpg");// também é possível escolher um banco aqui
if (!$conexao) {
    echo mysqli_connect_error();
    die();
}

$id = $_REQUEST["id"]; // esse array possui os valores dos parâmetros

if (!empty($id)) {
    $consulta = "DELETE FROM Enemy WHERE id = $id";
    $resultado_da_consulta = mysqli_query($conexao, $consulta);

    if ($resultado_da_consulta) {
        header("location: mostrar-elementos-do-banco.php"); //volta para página inicial
    } else {
        echo mysqli_error($conexao);
        mysqli_close($conexao);
        die();
    }
}
