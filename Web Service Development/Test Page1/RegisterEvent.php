<?php
    // POST로 전달받은 데이터를 출력
    echo "Name: ".$_POST["name"]."<br/>";
    echo "City: ".$_POST["city"];
    echo "DOB: ".$_POST["dob"];

    // DB와의 연결을 위한 정보설정
    $server_name = "localhost";
    $user_name = "root";
    $password = "";
    $db_name = "homework";

    echo "database insertion<br/>";
    // DB와의 Connection을 형성
    $conn = new mysqli($server_name, $user_name, $password, $db_name);
    // DB와의 Connection을 점검
    if($conn->connect_error) {
        die("Connection Failed: ".$conn->connect_error);
    }
    // 사용할 SQL문 생성 및 DB 전달
    $sql = "INSERT INTO registermatch (Name, City, DOB) 
        VALUES ('".$_POST["name"]."','".$_POST["city"]."','".$_POST["dob"]."') ";
    $result = mysqli_query($conn, $sql);

    // SQL문 전달결과에 따른 조건부 처리
    if ($result === TRUE) {
        echo "A record for tournament winner has been inserted.";
    } 
    else {
        printf("Could not insert record: %s\n", mysqli_error($mysqli));
    }

    echo '<h2><a href="lastprj.html">Home Site</a></h2>';

    // DB와의 연결을 해제
    mysqli_close($conn);
?>