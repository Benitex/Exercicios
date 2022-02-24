<?php

// Read

include "config.php";
$conexao = mysqli_connect($host, $usuario, $senha);
if (!$conexao) {
    echo mysqli_connect_error();
    die();
}

// seleciona um banco de dados
if (!mysqli_select_db($conexao, "RPG")) { // seleção de banco de dados
    echo mysqli_error($conexao);
    mysqli_close($conexao);
    die();
}

$consulta = "SELECT * FROM Enemy";
$resultado_da_consulta = mysqli_query($conexao, $consulta);

if (!$resultado_da_consulta) { // envia a consulta para o banco de dados e retorna falso caso ocorra um erro
    echo mysqli_error($conexao);
    mysqli_close($conexao);
    die();
}

// essa função criar um vetor que armazena os conteúdos das linhas do resultado da consulta do banco de dados
$linha = mysqli_fetch_assoc($resultado_da_consulta);
echo "<h1>Bestiário</h1><br/>";
echo "<a href='adicionar-elementos.php'><input type='button' value='Novo'></a><br/><br/>";
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
            <p>
                Type: $type <br/>
                HP: $hp <br/>
                Attack: $attack <br/>
                Defense: $defense <br/>
            </p>
            <a href="editar-elementos.php?id=$id"><input type="button" value="Editar"></a> 
            <a href="deletar-elementos.php?id=$id"><input type="button" value="Deletar"><br/></a>
            <br/>
END;
        echo $html;

        $linha = mysqli_fetch_assoc($resultado_da_consulta);
    }
}

mysqli_close($conexao);
