<?php

//estabelece a conexão
$conexao = mysqli_connect("localhost", "usuário", "senha");
if (!$conexao) { //verifica se ocorreu algum erro de conexão
    echo mysqli_connect_error(); //mostra o erro
    die(); //aborta a conexão
}

//cria uma consulta
$consulta = <<<END
    create database if not exists teste;

    create table teste (
        id int not null auto_increment,
        nome varchar(12),

        primary key(id)
    );

    insert into teste (nome) values ('Benito');
END;

if (mysqli_multi_query($conexao, $consulta)) { //envia a query para o banco de dados e retorna falso caso ocorra um erro
    echo 'Consulta realizada com sucesso';
} else {
    echo mysqli_error($conexao);
}

mysqli_close($conexao); //fecha a conexão