<?php
    require_once '../source/config.php';

    function database_connect()
    {
        $connection = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_SCHEMA);
        if ($connection->connect_errno) {
            die( 'Failed to connect to MySQL: ' . $connection->connect_error );
        }
        return $connection;
    }