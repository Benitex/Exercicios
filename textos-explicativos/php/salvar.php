<?php

$id = $_REQUEST["id"];
$hp = $_REQUEST["hp"];
$type = $_REQUEST["type"];
$attack = $_REQUEST["attack"];
$defense = $_REQUEST["defense"];

include "config.php";
$conexao = mysqli_connect($host, $usuario, $senha, "rpg");
if (!$conexao) {
    echo mysqli_connect_error();
    die();
}

if (empty($id)) {
    $consulta = "INSERT INTO enemy(type, hp, attack, defense) VALUES ('$type', '$hp', '$attack', '$defense')";
} else {
    $consulta = "UPDATE enemy SET type = '$type', hp = '$hp', attack = '$attack', defense = '$defense' WHERE id = $id";
}

if (mysqli_query($conexao, $consulta)) {
    header("location: mostrar-elementos-do-banco.php");
} else {
    echo "Erro na consulta: $consulta";
    echo mysqli_error($conexao);
    mysqli_close($conexao);
    die();
}
