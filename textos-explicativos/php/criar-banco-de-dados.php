<?php

include "config.php"; //esse arquivo possui as informações para conexão com banco de dados

//estabelece a conexão
$conexao = mysqli_connect($host, $usuario, $senha);
if (!$conexao) { //verifica se ocorreu algum erro de conexão
    echo mysqli_connect_error(); //mostra o erro
    die(); //aborta a conexão
}

$consulta = <<<END
    CREATE DATABASE IF NOT EXISTS RPG;

    CREATE TABLE Enemy (
        id INTEGER NOT NULL PRIMARY KEY AUTO_INCREMENT,
        HP INTEGER,
        type VARCHAR(10),
        attack INTEGER,
        defense INTEGER
    );
END;

$resultado_da_consulta = mysqli_multi_query($conexao, $consulta);

if (!$resultado_da_consulta) { //envia a consulta para o banco de dados e retorna falso caso ocorra um erro
    echo mysqli_error($conexao);
    mysqli_close($conexao);
    die();
}

mysqli_close($conexao); //fecha a conexão
