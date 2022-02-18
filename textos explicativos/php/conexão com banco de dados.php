<?php

//estabelece a conexão
$conexao = mysqli_connect("localhost", "user", "password");
if (!$conexao) { //verifica se ocorreu algum erro de conexão
    echo mysqli_connect_error(); //mostra o erro
    die(); //aborta a conexão
}

$consulta = "SELECT * FROM Enemy";

// seleciona um banco de dados
if (!mysqli_select_db($conexao, "RPG")) { //seleção de banco de dados
    echo mysqli_error($conexao);
    mysqli_close($conexao);
    die();
}

$resultado_da_consulta = mysqli_query($conexao, $consulta);

if (!$resultado_da_consulta) { //envia a consulta para o banco de dados e retorna falso caso ocorra um erro
    echo mysqli_error($conexao);
    mysqli_close($conexao);
    die();
}

mostrar_elementos_do_banco($resultado_da_consulta);

mysqli_close($conexao); //fecha a conexão

function criar_banco() {
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
    return $consulta;
}

function mostrar_elementos_do_banco($resultado_da_consulta) {
    //essa função criar um vetor que armazena os conteúdos das linhas do resultado da consulta do banco de dados
    $linha = mysqli_fetch_assoc($resultado_da_consulta);
    if (!$linha) {
        echo 'Tabela vazia';
    } else {
        while ($linha) {
            $id = $linha["id"];
            $hp = $linha["HP"];
            $type = $linha["type"];
            $attack = $linha["attack"];
            $defense = $linha["defense"];

            $html = <<<END
                Type: $type <br/>
                HP: $hp <br/>
                Attack: $attack <br/>
                Defense: $defense <br/>
                <br/>
    END;
            echo $html;

            $linha = mysqli_fetch_assoc($resultado_da_consulta);
        }
    }
}